# OnlyWarCCreator
Custom simple character creator for use with Only War Tabletop
Notes:  Uses a random system, no statbuy currently.  Also no enforcement, you have to trust your players.
*Talents:  due to a specific rules thing, if you have to pick something twice you get bonus exp.  Currently turned off in the creator, make note to do this manually.

Version: .58

NOTICE: as per Games Workshop IP Rules, let it be noted that this is a completely UNOFFICIAL tool.  As such, it also contains no extraneous rulebook info or descriptive texts, you must use your own rulebooks to be able to use the characters created here.

General:  This program works basically by pushing a bunch of text output to a charactersave.txt file.  You will have to transfer this information to another character sheet if you wish to use a proper one.

Regiment file creation:  There are two sample regiment files included, however since the number of possible regiments are numerous I cannot account for all rules at this moment so please message me if theres an edge case where the code cannot go.
Other than that, heres how it works (sections with ----- -----, descriptions afterwards):
-----
Name:
Homeworld:
World Type:
Regiment Type:
Officer Disposition: 
-----
////
These are all basic text, and are simply for housekeeping on the regiment file
////
-----
Characteristic Modifiers:
-----
////
These are automatically added in.  Be sure to use proper capitalization / spelling.
////
-----
Characteristic Choices:
-----
////
Seperate out choices with || on the same line.  Multiple choices can be on different lines.
If you put "choose:2"  at the beginning of the line, you get two choices from the same set, with elimination of previous choice.
////
-----
Skills:
-----
////
Put skills here: be sure they are spelled and capitalized correctly, because if you gain a skill twice you get Trained level.
////
-----
Traits:
-----
////
These are basically text that gets put on the character save wholesale: if you want actual stat effects, add these in manually in the appropriate spots.
////
-----
Talents:
-----
////
Same as skills, see source if you need proper comparisons.  You get bonus xp if you have to take something twice
*Note: currently turned off, needs more testing/work, do this manually*
////
-----
Talent Choices:
-----
////
See above: seperate choices out with || and put multiple choices on different lines
////
-----
Regiment Favored Weapons:
Basic Weapon:
Heavy Weapon:
-----
////
See rulebooks for how favored weapons work: these get added to class choices where appropriate
////
-----
Regiment Standard Kit:
-----
////
Pure text that is pushed to charactersave as part of inventory, along with class gear.
////
-----
Squad Gear:
-----
////
Gear that one single player doesn't own, simply added to regiment for housekeeping and to notify players its available
////

Program Use:  First, load up a regiment file by typing in the filename (must be in same folder) and pushing enter.
If you just press enter, it loads default.txt instead (you can save a regiment file as default.txt to create characters quickly).

Select choices by typing in a number and pressing enter.  A bad choice will be rejected.  If you input junk you will likely crash the program as there is no stream protection in this project.  To get the full extent of what each choice does, you need an official rulebook: there are no descriptions in the program itself.

Once you select your character, the game will read in from your regiment file and compare lists appropriately and change choices as needed.  Finish the program to output to CharacterSave.txt.  There is currently no rolls enforcements or statbuy systems, so you have to trust the players.

