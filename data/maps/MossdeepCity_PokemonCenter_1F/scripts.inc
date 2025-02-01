.set LOCALID_NURSE, 1

MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "The GYM LEADERS in this town are\n"
	.string "a formidable duo.\p"
	.string "Their combination attacks are, like,\n"
	.string "excellent and wow!$"



MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GiveJirachi, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_JIRACHI
 	givemon SPECIES_JIRACHI, 5, ITEM_TWISTED_SPOON
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_PokemonCenter_1F_EventScript_ReceiveJirachiParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_PokemonCenter_1F_EventScript_ReceiveJirachiPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end


MossdeepCity_PokemonCenter_1F_Text_GiveJirachi:
	.string "You must be a strong trainer.\n"
	.string "This is Jirachi. Please take \l"
	.string "good care of it.$"

MossdeepCity_PokemonCenter_1F_EventScript_ReceiveJirachiParty::
	call MossdeepCity_PokemonCenter_1F_EventScript_ReceiveJirachiFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_PokemonCenter_1F_EventScript_FinishReceivingJirachi
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_PokemonCenter_1F_EventScript_FinishReceivingJirachi
	end

MossdeepCity_PokemonCenter_1F_EventScript_ReceiveJirachiPC::
	call MossdeepCity_PokemonCenter_1F_EventScript_ReceiveJirachiFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_PokemonCenter_1F_EventScript_TransferJirachiToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_PokemonCenter_1F_EventScript_TransferJirachiToPC
	end


MossdeepCity_PokemonCenter_1F_EventScript_ReceiveJirachiFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_JIRACHI
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_PokemonCenter_1F_EventScript_Text_ReceivedJirachi
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_JIRACHI
	return

MossdeepCity_PokemonCenter_1F_EventScript_Text_ReceivedJirachi:
	.string "{PLAYER} received {STR_VAR_2}!$"


MossdeepCity_PokemonCenter_1F_EventScript_FinishReceivingJirachi::
	release
	end


MossdeepCity_PokemonCenter_1F_EventScript_TransferJirachiToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_PokemonCenter_1F_EventScript_FinishReceivingJirachi
	end
