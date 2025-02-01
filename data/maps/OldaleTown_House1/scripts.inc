OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	msgbox OldaleTown_House1_Text_GivePoochyenaX, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_POOCHYENA1
	givemon SPECIES_POOCHYENA1, 5, ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, OldaleTown_House1_EventScript_ReceivePoochyenaParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, OldaleTown_House1_EventScript_ReceivePoochyenaPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleTown_House1_Text_GivePoochyenaX:
	.string "Are you a POKEMON trainer?\p"
	.string "Do you think you can take this\n"
	.string "POOCHYENA with you on your journey?\p"
	.string "I feel bad but I think POOCHYENA\n"
	.string "would be happier with you.$"

OldaleTown_House1_EventScript_ReceivePoochyenaParty::
	call OldaleTown_House1_EventScript_ReceivePoochyenaFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_House1_EventScript_FinishReceivingPoochyena
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto OldaleTown_House1_EventScript_FinishReceivingPoochyena
	end

OldaleTown_House1_EventScript_ReceivePoochyenaPC::
	call OldaleTown_House1_EventScript_ReceivePoochyenaFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_House1_EventScript_TransferPoochyenaToPC
	call Common_EventScript_NameReceivedBoxMon
	goto OldaleTown_House1_EventScript_TransferPoochyenaToPC
	end


OldaleTown_House1_EventScript_ReceivePoochyenaFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_POOCHYENA1
	playfanfare MUS_OBTAIN_ITEM
	message OldaleTown_House1_EventScript_Text_ReceivedPoochyena
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_POOCHYENA1
	return

OldaleTown_House1_EventScript_Text_ReceivedPoochyena:
	.string "{PLAYER} received {STR_VAR_2}!$"


OldaleTown_House1_EventScript_FinishReceivingPoochyena::
	release
	end


OldaleTown_House1_EventScript_TransferPoochyenaToPC::
	call Common_EventScript_TransferredToPC
	goto OldaleTown_House1_EventScript_FinishReceivingPoochyena
	end
