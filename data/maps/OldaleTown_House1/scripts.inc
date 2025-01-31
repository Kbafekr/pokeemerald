OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	msgbox OldaleTown_House1_Text_GivePoochyenaX, MSGBOX_NPC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_POOCHYENA1
	givemon SPECIES_POOCHYENA1, 5, ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleTown_House1_Text_GivePoochyenaX:
	.string "Are you a POKEMON trainer?\p"
	.string "Do you think you can take POOCHYENA\n"
	.string "with you on your journey?\p"
	.string "I feel bad but I think POOCHYENA\n"
	.string "would be happier with you.\$"
