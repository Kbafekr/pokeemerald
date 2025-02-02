MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end




MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_GiveDuskullX, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DUSKULL1
	givemon SPECIES_DUSKULL1, 5, ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MtPyre_1F_EventScript_ReceiveDuskullParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MtPyre_1F_EventScript_ReceiveDuskullPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end
	end

MtPyre_1F_Text_GiveDuskullX:
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.\p"
	.string "Please take care of this DUSKULL.\p"


MtPyre_1F_EventScript_ReceiveDuskullParty::
	call MtPyre_1F_EventScript_ReceiveDuskullFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtPyre_1F_EventScript_FinishReceivingDuskull
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MtPyre_1F_EventScript_FinishReceivingDuskull
	end

MtPyre_1F_EventScript_ReceiveDuskullPC::
	call MtPyre_1F_EventScript_ReceiveDuskullFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtPyre_1F_EventScript_TransferDuskullToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MtPyre_1F_EventScript_TransferDuskullToPC
	end


MtPyre_1F_EventScript_ReceiveDuskullFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_DUSKULL1
	playfanfare MUS_OBTAIN_ITEM
	message MtPyre_1F_EventScript_Text_ReceivedDuskull
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_DUSKULL1
	return

MtPyre_1F_EventScript_Text_ReceivedDuskull:
	.string "{PLAYER} received {STR_VAR_2}!$"


MtPyre_1F_EventScript_FinishReceivingDuskull::
	release
	end


MtPyre_1F_EventScript_TransferDuskullToPC::
	call Common_EventScript_TransferredToPC
	goto MtPyre_1F_EventScript_FinishReceivingDuskull
	end












MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"


MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"
