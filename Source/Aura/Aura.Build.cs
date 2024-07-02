// Aura Game, Copyright moonabyss. All Rights Reserved.

using UnrealBuildTool;

public class Aura : ModuleRules
{
    public Aura(ReadOnlyTargetRules Target)
        : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities", "UMG", "CoreUObject" });
        PublicIncludePaths.AddRange(new string[] { "Aura" });
        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks", "NavigationSystem" });
    }
}
