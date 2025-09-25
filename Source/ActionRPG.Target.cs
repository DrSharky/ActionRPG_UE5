// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PunkRPGTarget : TargetRules
{
	public PunkRPGTarget(TargetInfo Target)
		: base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.AddRange(new string[] { "PunkRPG" });

		DefaultBuildSettings = BuildSettingsVersion.V5;
	}
}
