// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class VampRPGTarget : TargetRules
{
	public VampRPGTarget(TargetInfo Target)
		: base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.AddRange(new string[] { "VampRPG" });

		DefaultBuildSettings = BuildSettingsVersion.V5;
	}
}
