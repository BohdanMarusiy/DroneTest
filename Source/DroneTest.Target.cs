// Test assimenght for job.

using UnrealBuildTool;
using System.Collections.Generic;

public class DroneTestTarget : TargetRules
{
	public DroneTestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "DroneTest" } );
	}
}
