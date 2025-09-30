// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PunkRPGEditorTarget : TargetRules
{
	public PunkRPGEditorTarget(TargetInfo Target)
		: base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange(new string[] { "PunkRPG" });

		DefaultBuildSettings = BuildSettingsVersion.V5;
	}
}
