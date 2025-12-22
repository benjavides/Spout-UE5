/**
 * Implements the sender/receiver registry, handling shared resource lifetimes and Spout
 * name registration used by both sender and receiver paths.
 */
#include "SpoutSenderRegistry.h"
#include "SpoutD3DContext.h"

FSpoutSharedSender::FSpoutSharedSender(FName InName, ESpoutType InType)
	: Name(InName)
	, Type(InType)
{
}

FSpoutSharedSender::~FSpoutSharedSender()
{
	// Ensure shared handles are released before destruction.
	ReleaseResources();
}

void FSpoutSharedSender::ReleaseResources()
{
	// Release shared textures and cached wrappers under lock.
	FScopeLock Lock(&ResourceMutex);
	SharedTexture.Reset();
	StagingTexture.Reset();
	CachedWrappedResource.Reset();
	GammaTexture.Reset();
	GammaRTV.Reset();

	SharedHandle = nullptr;
	CachedNativeResource = nullptr;

	if (Type == ESpoutType::Sender)
	{
		FSpoutD3DContext& Context = FSpoutD3DContext::Get();
		spoutSenderNames* SenderNames = Context.GetSenderNames();
		if (SenderNames)
		{
			// Unregister the sender name from Spout's global list.
			FScopeLock SpoutLock(&Context.GetSpoutMutex());
			SenderNames->ReleaseSenderName(TCHAR_TO_UTF8(*Name.ToString()));
		}
	}

	bRegistered = false;
}

FSpoutSenderRegistry& FSpoutSenderRegistry::Get()
{
	static FSpoutSenderRegistry Instance;
	return Instance;
}

TSharedPtr<FSpoutSharedSender> FSpoutSenderRegistry::FindOrAdd(const FName& Name, ESpoutType Type)
{
	// Registry access is shared across game/render threads.
	FScopeLock Lock(&Mutex);

	if (TSharedPtr<FSpoutSharedSender>* Existing = Senders.Find(Name))
	{
		return *Existing;
	}

	TSharedPtr<FSpoutSharedSender> NewSender = MakeShared<FSpoutSharedSender>(Name, Type);
	Senders.Add(Name, NewSender);
	return NewSender;
}

TSharedPtr<FSpoutSharedSender> FSpoutSenderRegistry::Find(const FName& Name)
{
	FScopeLock Lock(&Mutex);
	if (TSharedPtr<FSpoutSharedSender>* Existing = Senders.Find(Name))
	{
		return *Existing;
	}
	return nullptr;
}

void FSpoutSenderRegistry::Remove(const FName& Name)
{
	FScopeLock Lock(&Mutex);
	Senders.Remove(Name);
}

void FSpoutSenderRegistry::Clear()
{
	FScopeLock Lock(&Mutex);
	Senders.Empty();
}
