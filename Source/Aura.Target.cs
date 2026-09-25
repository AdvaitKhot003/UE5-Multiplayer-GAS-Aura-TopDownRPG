// No Copyright.

using UnrealBuildTool;

public class AuraTarget : TargetRules
{
	public AuraTarget(TargetInfo target) : base(target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		
		ExtraModuleNames.AddRange(
		[
			"Aura"
		]);
	}
}
