.set LOCALID_NURSE, 1

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "Even if a POKéMON faints and can't\n"
	.string "battle, it can still use a move learned\l"
	.string "from a HIDDEN MACHINE (HM).$"




DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARON1
	givemon SPECIES_ARON1, 5, ITEM_METAL_COAT
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, DewfordTown_PokemonCenter_1F_EventScript_ReceiveAronParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, DewfordTown_PokemonCenter_1F_EventScript_ReceiveAronPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end


DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.\p"
	.string "You can also get rare POKEMON\n"
	.string "like this ARON I found.\p"
	.string "Here, you can have this one.$"



DewfordTown_PokemonCenter_1F_EventScript_ReceiveAronParty::
	call DewfordTown_PokemonCenter_1F_EventScript_ReceiveAronFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordTown_PokemonCenter_1F_EventScript_FinishReceivingAron
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto DewfordTown_PokemonCenter_1F_EventScript_FinishReceivingAron
	end

DewfordTown_PokemonCenter_1F_EventScript_ReceiveAronPC::
	call DewfordTown_PokemonCenter_1F_EventScript_ReceiveAronFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordTown_PokemonCenter_1F_EventScript_TransferAronToPC
	call Common_EventScript_NameReceivedBoxMon
	goto DewfordTown_PokemonCenter_1F_EventScript_TransferAronToPC
	end


DewfordTown_PokemonCenter_1F_EventScript_ReceiveAronFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_ARON1
	playfanfare MUS_OBTAIN_ITEM
	message DewfordTown_PokemonCenter_1F_EventScript_Text_ReceivedAron
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ARON1
	return

DewfordTown_PokemonCenter_1F_EventScript_Text_ReceivedAron:
	.string "{PLAYER} received {STR_VAR_2}!$"


DewfordTown_PokemonCenter_1F_EventScript_FinishReceivingAron::
	release
	end


DewfordTown_PokemonCenter_1F_EventScript_TransferAronToPC::
	call Common_EventScript_TransferredToPC
	goto DewfordTown_PokemonCenter_1F_EventScript_FinishReceivingAron
	end
