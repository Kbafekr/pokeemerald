.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end





FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ABSOL1
	givemon SPECIES_ABSOL1, 20, ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, FortreeCity_PokemonCenter_1F_EventScript_ReceiveAbsolParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, FortreeCity_PokemonCenter_1F_EventScript_ReceiveAbsolPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Listen, kid, are you working\n"
	.string "on a POKéDEX?\p"
	.string "Hmm… Go to the SAFARI ZONE.\n"
	.string "That's my suggestion.\p"
	.string "Here's an ABSOL I found that\n"
	.string "might help you on your journey.$"

FortreeCity_PokemonCenter_1F_EventScript_ReceiveAbsolParty::
	call FortreeCity_PokemonCenter_1F_EventScript_ReceiveAbsolFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_PokemonCenter_1F_EventScript_FinishReceivingAbsol
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FortreeCity_PokemonCenter_1F_EventScript_FinishReceivingAbsol
	end

FortreeCity_PokemonCenter_1F_EventScript_ReceiveAbsolPC::
	call FortreeCity_PokemonCenter_1F_EventScript_ReceiveAbsolFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_PokemonCenter_1F_EventScript_TransferAbsolToPC
	call Common_EventScript_NameReceivedBoxMon
	goto FortreeCity_PokemonCenter_1F_EventScript_TransferAbsolToPC
	end


FortreeCity_PokemonCenter_1F_EventScript_ReceiveAbsolFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_ABSOL1
	playfanfare MUS_OBTAIN_ITEM
	message FortreeCity_PokemonCenter_1F_EventScript_Text_ReceiveAbsol
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ABSOL1
	return

FortreeCity_PokemonCenter_1F_EventScript_Text_ReceiveAbsol:
	.string "{PLAYER} received {STR_VAR_2}!$"


FortreeCity_PokemonCenter_1F_EventScript_FinishReceivingAbsol::
	release
	end


FortreeCity_PokemonCenter_1F_EventScript_TransferAbsolToPC::
	call Common_EventScript_TransferredToPC
	goto FortreeCity_PokemonCenter_1F_EventScript_FinishReceivingAbsol
	end






FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Have you done anything at\n"
	.string "the RECORD CORNER?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of TRAINERS.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wow, you have a POKéNAV!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about POKéNAV's\n"
	.string "MATCH CALL system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered TRAINERS anytime.\p"
	.string "It also shows you which TRAINERS\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those DEVON guys\n"
	.string "sure know what they're doing!$"
