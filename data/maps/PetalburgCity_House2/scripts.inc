PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN became our town's new\n"
	.string "GYM LEADER.\p"
	.string "I think he called his family over from\n"
	.string "somewhere far away.$"


PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RALTS1
	givemon SPECIES_RALTS1, 5, ITEM_TWISTED_SPOON
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PetalburgCity_House2_EventScript_ReceiveRaltsParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PetalburgCity_House2_EventScript_ReceiveRaltsPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "I battled NORMAN once, but, whew,\n"
	.string "he was way too strong.\p"
	.string "How would I put it?\p"
	.string "I just got the feeling that he\n"
	.string "lives for POKéMON.\p"
	.string "He gave me this RALTS,\n"
	.string "but maybe you should have it.$"


PetalburgCity_House2_EventScript_ReceiveRaltsParty::
	call PetalburgCity_House2_EventScript_ReceiveRaltsFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_House2_EventScript_FinishReceivingRalts
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PetalburgCity_House2_EventScript_FinishReceivingRalts
	end

PetalburgCity_House2_EventScript_ReceiveRaltsPC::
	call PetalburgCity_House2_EventScript_ReceiveRaltsFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_House2_EventScript_TransferRaltsToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PetalburgCity_House2_EventScript_TransferRaltsToPC
	end


PetalburgCity_House2_EventScript_ReceiveRaltsFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_RALTS1
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_House2_EventScript_Text_ReceivedRalts
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_RALTS1
	return

PetalburgCity_House2_EventScript_Text_ReceivedRalts:
	.string "{PLAYER} received {STR_VAR_2}!$"


PetalburgCity_House2_EventScript_FinishReceivingRalts::
	release
	end


PetalburgCity_House2_EventScript_TransferRaltsToPC::
	call Common_EventScript_TransferredToPC
	goto PetalburgCity_House2_EventScript_FinishReceivingRalts
	end
