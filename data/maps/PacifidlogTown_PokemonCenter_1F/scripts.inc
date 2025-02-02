.set LOCALID_NURSE, 1

PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "PACIFIDLOG TOWN floats on top of\n"
	.string "a colony of CORSOLA.\p"
	.string "If I told you that, would you believe\n"
	.string "me?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "The ancestors of the people in\n"
	.string "PACIFIDLOG were said to have been\l"
	.string "born on boats and then lived and died \l"
	.string "aboard them.\p"
	.string "I understand that they lived that way\n"
	.string "because they were searching for\l"
	.string "something.$"



PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BAGON1
	givemon SPECIES_BAGON1, 20, ITEM_DRAGON_FANG
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PacifidlogTown_PokemonCenter_1F_EventScript_ReceiveBagonParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PacifidlogTown_PokemonCenter_1F_EventScript_ReceiveBagonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "What color is your TRAINER CARD?\n"
	.string "Mine's copper!\p"
	.string "Here, I was given this BAGON,\n"
	.string "but I don't think I'm strong\l"
	.string "enough to raise it.$"

PacifidlogTown_PokemonCenter_1F_EventScript_ReceiveBagonParty::
	call PacifidlogTown_PokemonCenter_1F_EventScript_ReceiveBagonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_PokemonCenter_1F_EventScript_FinishReceivingBagon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PacifidlogTown_PokemonCenter_1F_EventScript_FinishReceivingBagon
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ReceiveBagonPC::
	call PacifidlogTown_PokemonCenter_1F_EventScript_ReceiveBagonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_PokemonCenter_1F_EventScript_TransferBagonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PacifidlogTown_PokemonCenter_1F_EventScript_TransferBagonToPC
	end


PacifidlogTown_PokemonCenter_1F_EventScript_ReceiveBagonFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BAGON1
	playfanfare MUS_OBTAIN_ITEM
	message PacifidlogTown_PokemonCenter_1F_Text_ReceivedBagon
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BAGON1
	return

PacifidlogTown_PokemonCenter_1F_Text_ReceivedBagon:
	.string "{PLAYER} received {STR_VAR_2}!$"


PacifidlogTown_PokemonCenter_1F_EventScript_FinishReceivingBagon::
	release
	end


PacifidlogTown_PokemonCenter_1F_EventScript_TransferBagonToPC::
	call Common_EventScript_TransferredToPC
	goto PacifidlogTown_PokemonCenter_1F_EventScript_FinishReceivingBagon
	end
