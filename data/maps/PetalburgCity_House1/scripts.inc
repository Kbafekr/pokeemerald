PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_GoOnAdventure:
	.string "Sigh…\p"
	.string "I wish I could go on an adventure\n"
	.string "with some POKéMON…\p"
	.string "Crawl through some damp grass…\n"
	.string "Climb rocky, rugged mountains…\p"
	.string "Cross the raging seas…\n"
	.string "Wander about in dark caves…\p"
	.string "And, sometimes, even get a little\n"
	.string "homesick…\p"
	.string "It must be fabulous to travel!$"


PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_GiveTaillowX, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAILLOW1
	givemon SPECIES_TAILLOW1, 5, ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PetalburgCity_House1_EventScript_ReceiveTaillowParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PetalburgCity_House1_EventScript_ReceiveTaillowPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end


PetalburgCity_House1_Text_GiveTaillowX:
	.string "I found this TAILLOW outside.\p"
	.string "Here, let it tag along with you \n"
	.string "on your adventure!$"

PetalburgCity_House1_EventScript_ReceiveTaillowParty::
	call PetalburgCity_House1_EventScript_ReceiveTaillowFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_House1_EventScript_FinishReceivingTaillow
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PetalburgCity_House1_EventScript_FinishReceivingTaillow
	end

PetalburgCity_House1_EventScript_ReceiveTaillowPC::
	call PetalburgCity_House1_EventScript_ReceiveTaillowFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_House1_EventScript_TransferTaillowToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PetalburgCity_House1_EventScript_TransferTaillowToPC
	end


PetalburgCity_House1_EventScript_ReceiveTaillowFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_TAILLOW1
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_House1_EventScript_Text_ReceivedTaillow
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_TAILLOW1
	return

PetalburgCity_House1_EventScript_Text_ReceivedTaillow:
	.string "{PLAYER} received {STR_VAR_2}!$"


PetalburgCity_House1_EventScript_FinishReceivingTaillow::
	release
	end


PetalburgCity_House1_EventScript_TransferTaillowToPC::
	call Common_EventScript_TransferredToPC
	goto PetalburgCity_House1_EventScript_FinishReceivingTaillow
	end
