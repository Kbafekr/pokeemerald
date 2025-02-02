SootopolisCity_House5_MapScripts::
	.byte 0

SootopolisCity_House5_EventScript_Maniac::
	msgbox SootopolisCity_House5_Text_SootopolisMtPyreConnection, MSGBOX_NPC
	end

SootopolisCity_House5_Text_SootopolisMtPyreConnection:
	.string "There appears to be some connection\n"
	.string "between SOOTOPOLIS and MT. PYRE.\p"
	.string "My friends and I did some research on\n"
	.string "it at the lab where I used to work.$"




SootopolisCity_House5_EventScript_Girl::
	msgbox SootopolisCity_House5_Text_BrotherUsedToStudySea, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM1
	givemon SPECIES_BELDUM1, 15, ITEM_CHOICE_BAND
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SootopolisCity_House5_EventScript_ReceiveBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SootopolisCity_House5_EventScript_ReceiveBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

SootopolisCity_House5_Text_BrotherUsedToStudySea:
	.string "My big brother used to study the sea.\p"
	.string "He gave me this BELDUM,\n"
	.string "but I think you should have it.$"


SootopolisCity_House5_EventScript_ReceiveBeldumParty::
	call SootopolisCity_House5_EventScript_ReceiveBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_House5_EventScript_FinishReceivingBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SootopolisCity_House5_EventScript_FinishReceivingBeldum
	end

SootopolisCity_House5_EventScript_ReceiveBeldumPC::
	call SootopolisCity_House5_EventScript_ReceiveBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_House5_EventScript_TransferBeldumToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SootopolisCity_House5_EventScript_TransferBeldumToPC
	end


SootopolisCity_House5_EventScript_ReceiveBeldumFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM1
	playfanfare MUS_OBTAIN_ITEM
	message SootopolisCity_House5_EventScript_Text_ReceivedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM1
	return

SootopolisCity_House5_EventScript_Text_ReceivedBeldum:
	.string "{PLAYER} received {STR_VAR_2}!$"


SootopolisCity_House5_EventScript_FinishReceivingBeldum::
	release
	end


SootopolisCity_House5_EventScript_TransferBeldumToPC::
	call Common_EventScript_TransferredToPC
	goto SootopolisCity_House5_EventScript_FinishReceivingBeldum
	end
