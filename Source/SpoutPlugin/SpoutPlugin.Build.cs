using System;
using System.IO;
using UnrealBuildTool;

public class SpoutPlugin : ModuleRules
{
    private string ModulePath {
        // Plugin root directory (two levels up from ModuleDirectory).
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../")); }
    }

    private string ThirdPartyPath {
        // Third-party dependencies bundled with the plugin.
        get { return Path.GetFullPath(Path.Combine(ModulePath, "ThirdParty/")); }
    }

    public string GetUProjectPath()
    {
        // Resolve the .uproject root (used to copy runtime DLLs).
        return Path.Combine(ModuleDirectory, "../../../..");
    }

    private string CopyToProjectBinaries(string Filepath, ReadOnlyTargetRules Target)
    {
        // Ensures the Spout runtime DLL is staged in the project's Binaries folder.
        string BinariesDir = Path.Combine(GetUProjectPath(), "Binaries", Target.Platform.ToString());
        string Filename = Path.GetFileName(Filepath);
        string FullBinariesDir = Path.GetFullPath(BinariesDir);

        if (!Directory.Exists(FullBinariesDir)) Directory.CreateDirectory(FullBinariesDir);

        string FullExistingPath = Path.Combine(FullBinariesDir, Filename);
        if (!File.Exists(FullExistingPath))
        {
            File.Copy(Filepath, FullExistingPath, true);
        }
        return FullExistingPath;
    }

    public SpoutPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
            Path.Combine(ModuleDirectory, "Public"),
            Path.Combine(ThirdPartyPath, "Spout", "include")
        });

        PrivateIncludePaths.AddRange(new string[] {
            "SpoutPlugin/Private",
        });

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "RHI",
            "RenderCore",
            "D3D12RHI", 
            "D3D11RHI"
        });

        // Pull in engine DX11/DX12 libs for D3D11-on-12 interop.
        AddEngineThirdPartyPrivateStaticDependencies(Target, "DX12");
        AddEngineThirdPartyPrivateStaticDependencies(Target, "DX11");

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "ApplicationCore", "Slate", "SlateCore"
        });

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            string PlatformString = "amd64";
            // Link against the Spout import library and stage the DLL.
            PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "Spout", "lib", PlatformString, "Spout.lib"));
            PublicSystemLibraries.Add("d3dcompiler.lib");
            
            string pluginDLLPath = Path.Combine(ThirdPartyPath, "Spout", "lib", PlatformString, "Spout.dll");
            string binariesPath = CopyToProjectBinaries(pluginDLLPath, Target);
            RuntimeDependencies.Add(binariesPath);
        }
    }
}
