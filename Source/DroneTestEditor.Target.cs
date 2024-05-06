// Test assimenght for job.

using UnrealBuildTool;
using System.Collections.Generic;

public class DroneTestEditorTarget : TargetRules
{
	public DroneTestEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "DroneTest" } );
	}
}
