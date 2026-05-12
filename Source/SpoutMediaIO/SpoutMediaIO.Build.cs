using System.IO;
using UnrealBuildTool;

public class SpoutMediaIO : ModuleRules
{
    public SpoutMediaIO(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        // Access SpoutSender.h (private to SpoutPlugin) for the render-thread send API.
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "../SpoutPlugin/Private"));

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "MediaAssets",
            "MediaIOCore",
            "SpoutPlugin"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "DisplayCluster",
            "RenderCore",
            "RHI"
        });
    }
}
