stock SetPlayerCameraLoginPosition(playerid)
{
	TogglePlayerSpectating(playerid, 1);
	new slot = Random(sizeof(logincameraInfo));

	InterpolateCameraPos(playerid, logincameraInfo[slot][logincameraFromPositionX], logincameraInfo[slot][logincameraFromPositionY], logincameraInfo[slot][logincameraFromPositionZ], logincameraInfo[slot][logincameraToPositionX], logincameraInfo[slot][logincameraToPositionY], logincameraInfo[slot][logincameraToPositionZ], 10000);
	InterpolateCameraLookAt(playerid, logincameraInfo[slot][logincameraFromLookX], logincameraInfo[slot][logincameraFromLookY], logincameraInfo[slot][logincameraFromLookZ], logincameraInfo[slot][logincameraToLookX], logincameraInfo[slot][logincameraToLookY], logincameraInfo[slot][logincameraToLookZ], 10000);
	return 1;
}