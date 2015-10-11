#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
enum STATNAMES {WEAPON_SKILL, BALLISTIC_SKILL, STRENGTH, TOUGHNESS, AGILITY, INTELLIGENCE, PERCEPTION, WILLPOWER, FELLOWSHIP, WOUNDS};
enum SPECIALISTS {NO_SPECIALIST, HEAVY_GUNNER, MEDIC, OPERATOR, SERGEANT,
                  WEAPONS_SPECIALIST, COMMISAR, MINISTORUM_PRIEST, OGRYN, RATLING,
                  SANCTIONED_PSYKER, STORM_TROOPER, TECH_PRIEST_ENGINSEER};

struct STRINGCHOICE
{
    std::vector <std::string> choices;
};

struct STRINGINTCHOICE
{
    std::vector <std::string> choices;
    std::vector <int> choicesints;
    std::vector <int> choicesintamount;
};

struct REGIMENT
{
    std::string regimentname;
    std::string regimenthomeworld;// = "Viridian";
    std::string regimentworldtype;// = "Agri World";
    std::string regimenttype;// = "Light Infantry";
    std::string regimentofficer;
    int regimentcharmods[10];
    std::vector <STRINGINTCHOICE> regimentcharmodopt;

    std::vector <std::string> regimenttalents;
    std::vector <STRINGCHOICE> regimenttalentsopt;
    std::vector <std::string> regimentskills;
    std::vector <STRINGCHOICE> regimentskillsopt;
    std::vector <std::string> regimenttraits;
    std::vector <std::string> regimentaptitudes;
    std::vector <std::string> regimentfavoredbasic;
    std::vector <std::string> regimentfavoredheavy;
    std::vector <std::string> regimentdrawbacks;
    std::vector <std::string> regimentequipment;

    //for choices in statloading
    std::vector <unsigned int> regimentcharmodoptchoicenumber;


    REGIMENT();
    bool loadregimentfile(std::string regimentfile);
    ~REGIMENT();

} regiment;

REGIMENT::REGIMENT()
{
    for (int i = 0; i < 10; i++)
        regiment.regimentcharmods[i] = 0;

}

REGIMENT::~REGIMENT()
{

}

bool REGIMENT::loadregimentfile(std::string regimentfile)
{
    using namespace std;
    ifstream rfile;
    rfile.open(regimentfile.c_str());
    if (!rfile.is_open())
        return false;
    ofstream outfile;
    //outfile.open("testoutput.txt");
    while (!rfile.eof())
    {
        string intxt;
        getline(rfile, intxt);
        size_t findpos;
        if ((findpos=intxt.find("Name: "))!=string::npos)
        {
            intxt.erase(findpos, findpos+6);
            regimentname = intxt;
            outfile<<regimentname.c_str();
            outfile<<'\n';
        }
        if ((findpos=intxt.find("Homeworld: "))!=string::npos)
        {
            intxt.erase(findpos, findpos+11);
            regimenthomeworld = intxt;
            outfile<<regimenthomeworld.c_str();
            outfile<<'\n';
        }
        if ((findpos=intxt.find("World Type: "))!=string::npos)
        {
            intxt.erase(findpos, findpos+12);
            regimentworldtype = intxt;
            outfile<<regimentworldtype.c_str();
            outfile<<'\n';
        }
        if ((findpos=intxt.find("Regiment Type: "))!=string::npos)
        {
            intxt.erase(findpos, findpos+15);
            regimenttype = intxt;
            outfile<<regimenttype.c_str();
            outfile<<'\n';
        }
        if ((findpos=intxt.find("Officer Disposition: "))!=string::npos)
        {
            intxt.erase(findpos, findpos+21);
            regimentofficer = intxt;
            outfile<<regimentofficer.c_str();
            outfile<<'\n';
        }
        if ((findpos=intxt.find("Characteristic Modifiers:"))!=string::npos)
        { //start looking thru charmods
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                if (intxt.find("Weapon Skill")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[WEAPON_SKILL] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Ballistic Skill")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[BALLISTIC_SKILL] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Strength")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[STRENGTH] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Toughness")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[TOUGHNESS] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Agility")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[AGILITY] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Intelligence")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[INTELLIGENCE] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Perception")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[PERCEPTION] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Willpower")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[WILLPOWER] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Fellowship")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[FELLOWSHIP] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                if (intxt.find("Wounds")!=string::npos)
                {
                    char amt = intxt[1];
                    char sign = intxt[0];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    regimentcharmods[WOUNDS] += amti;
                    intxt.erase(findpos, findpos+3);
                    outfile<<intxt.c_str();
                    outfile<<amti;
                    outfile<<'\n';
                }
                intxt.clear();
                getline(rfile, intxt);
            }

        }

        if ((findpos=intxt.find("Characteristic Choices:"))!=string::npos) //loaded later into statchoices
        {
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                if (intxt.find("choose:2"))
                    regiment.regimentcharmodoptchoicenumber.push_back(2);
                else
                    regiment.regimentcharmodoptchoicenumber.push_back(1);
                STRINGINTCHOICE skillmod;
                if ((findpos=intxt.find("Weapon Skill"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Weapon Skill");
                    skillmod.choicesints.push_back(WEAPON_SKILL);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 12).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Ballistic Skill"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Ballistic Skill");
                    skillmod.choicesints.push_back(BALLISTIC_SKILL);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 15).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Strength"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Strength");
                    skillmod.choicesints.push_back(STRENGTH);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 8).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Toughness"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Toughness");
                    skillmod.choicesints.push_back(TOUGHNESS);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 9).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Agility"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Agility");
                    skillmod.choicesints.push_back(AGILITY);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 7).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Intelligence"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Intelligence");
                    skillmod.choicesints.push_back(INTELLIGENCE);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 12).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Perception"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Perception");
                    skillmod.choicesints.push_back(PERCEPTION);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 10).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Willpower"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Willpower");
                    skillmod.choicesints.push_back(WILLPOWER);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 9).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Fellowship"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Fellowship");
                    skillmod.choicesints.push_back(FELLOWSHIP);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 10).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                if ((findpos=intxt.find("Wounds"))!=string::npos)
                {

                    char amt = intxt[findpos - 2];
                    char sign = intxt[findpos - 3];
                    int amti = amt-48;
                    if (sign == '-')
                        amti *=-1;
                    skillmod.choices.push_back("Wounds");
                    skillmod.choicesints.push_back(WOUNDS);
                    skillmod.choicesintamount.push_back(amti);

                    outfile<<intxt.substr(findpos, 6).c_str();
                    outfile<<amti;
                    outfile<<" || ";
                }
                regimentcharmodopt.push_back(skillmod);
                intxt.clear();
                getline(rfile, intxt);
                outfile<<'\n';
            }
        }

        if ((findpos=intxt.find("Skills:"))!=string::npos) //loaded later into statchoices
        {
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                //dont have to find them, just add
                regimentskills.push_back(intxt.c_str());
                outfile<<intxt.c_str();
                outfile<<'\n';

                intxt.clear();
                getline(rfile, intxt);
            }
        }

        if ((findpos=intxt.find("Skill Choices:"))!=string::npos) //loaded later into statchoices
        {
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                //each choice is separated by ||, find first one, add substring, then keep going till reach end
                STRINGCHOICE skillchoice;
                while ((findpos = intxt.find("||"))!=string::npos)
                {

                    string optmod = intxt.substr(0, findpos-1).c_str();
                    skillchoice.choices.push_back(optmod.c_str());
                    outfile << optmod.c_str();
                    //outfile << findpos;
                    outfile << " || ";
                    intxt = intxt.substr(findpos+3);
                }
                if (intxt.size()>3)
                {
                    skillchoice.choices.push_back(intxt.c_str());
                    outfile << intxt.c_str();
                    outfile<<'\n';
                }
                regimentskillsopt.push_back(skillchoice);

                //outfile<<intxt.c_str();
                outfile<<'\n';

                intxt.clear();
                getline(rfile, intxt);
            }
        }

        if ((findpos=intxt.find("Traits:"))!=string::npos) //loaded later into statchoices
        {
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                //dont have to find them, just add
                regimenttraits.push_back(intxt.c_str());
                outfile<<intxt.c_str();
                outfile<<'\n';

                intxt.clear();
                getline(rfile, intxt);
            }
        }

        if ((findpos=intxt.find("Talents:"))!=string::npos) //loaded later into statchoices
        {
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                //dont have to find them, just add
                regimenttalents.push_back(intxt.c_str());
                outfile<<intxt.c_str();
                outfile<<'\n';

                intxt.clear();
                getline(rfile, intxt);
            }
        }

        if ((findpos=intxt.find("Talent Choices:"))!=string::npos) //loaded later into statchoices
        {
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                //each choice is separated by ||, find first one, add substring, then keep going till reach end
                STRINGCHOICE talchoice;
                while ((findpos = intxt.find("||"))!=string::npos)
                {

                    string optmod = intxt.substr(0, findpos-1).c_str();
                    talchoice.choices.push_back(optmod.c_str());
                    outfile << optmod.c_str();
                    //outfile << findpos;
                    outfile << " || ";
                    intxt = intxt.substr(findpos+3);
                }
                if (intxt.size()>3)
                {
                    talchoice.choices.push_back(intxt.c_str());
                    outfile << intxt.c_str();
                    outfile<<'\n';
                }
                regimenttalentsopt.push_back(talchoice);

                //outfile<<intxt.c_str();
                outfile<<'\n';

                intxt.clear();
                getline(rfile, intxt);
            }
        }

        if ((findpos=intxt.find("Weapon Choices:"))!=string::npos) //loaded later into statchoices
        {
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                //each choice is separated by ||, find first one, add substring, then keep going till reach end
                STRINGCHOICE wepchoice;
                while ((findpos = intxt.find("||"))!=string::npos)
                {

                    string optmod = intxt.substr(0, findpos-1).c_str();
                    wepchoice.choices.push_back(optmod.c_str());
                    outfile << optmod.c_str();
                    //outfile << findpos;
                    outfile << " || ";
                    intxt = intxt.substr(findpos+3);
                }
                if (intxt.size()>3)
                {
                    wepchoice.choices.push_back(intxt.c_str());
                    outfile << intxt.c_str();
                    outfile<<'\n';
                }
                regimenttalentsopt.push_back(wepchoice);

                //outfile<<intxt.c_str();
                outfile<<'\n';

                intxt.clear();
                getline(rfile, intxt);
            }
        }

        if ((findpos=intxt.find("Regiment Favored Weapons:"))!=string::npos) //loaded later into statchoices
        {
            getline(rfile, intxt);
            while (intxt.size()>3)
            {
                if((findpos = intxt.find("Basic Weapon: "))!=string::npos)
                {
                    regimentfavoredbasic.push_back(intxt.substr(findpos+14).c_str());
                    outfile<<intxt.substr(findpos+14).c_str();
                    outfile<<'\n';
                }
                if((findpos = intxt.find("Heavy Weapon: "))!=string::npos)
                {
                    regimentfavoredheavy.push_back(intxt.substr(findpos+14).c_str());
                    outfile<<intxt.substr(findpos+14).c_str();
                    outfile<<'\n';
                }
                intxt.clear();
                getline(rfile, intxt);
            }
        }

        if ((findpos=intxt.find("Regiment Standard Kit:"))!=string::npos)
        {
            getline(rfile, intxt);
            while (intxt.size()>3) //add them as they are
            {
                regimentequipment.push_back(intxt.c_str());
                outfile<<intxt<<'\n';
                intxt.clear();
                getline(rfile, intxt);
            }
        }

        if ((findpos=intxt.find("Squad Gear:"))!=string::npos)
        {
            getline(rfile, intxt);
            while (intxt.size()>3) //add them as they are
            {
                intxt+=" (Squad)";
                regimentequipment.push_back(intxt.c_str());
                outfile<<intxt<<'\n';
                intxt.clear();
                getline(rfile, intxt);
            }
        }





    }
    outfile.close();
    rfile.close();


    return true;
}

bool loadregiment(std::string regimentfile)
{
    return regiment.loadregimentfile(regimentfile.c_str());
}

int main()
{

    using namespace::std;
    srand(time(NULL));


    vector <string> weapontraining;
    weapontraining.push_back("Weapon Training: Bolt");
    weapontraining.push_back("Weapon Training: Chain");
    weapontraining.push_back("Weapon Training: Flame");
    weapontraining.push_back("Weapon Training: Heavy");
    weapontraining.push_back("Weapon Training: Las");
    weapontraining.push_back("Weapon Training: Launcher");
    weapontraining.push_back("Weapon Training: Melta");
    weapontraining.push_back("Weapon Training: Plasma");
    weapontraining.push_back("Weapon Training: Power");
    weapontraining.push_back("Weapon Training: Low-Tech");
    weapontraining.push_back("Weapon Training: Shock");
    weapontraining.push_back("Weapon Training: Solid Projectile");


    //ballistic mechandendrite:
    vector <string> cybernetics;
    cybernetics.push_back("Augur Array");
    cybernetics.push_back("Autosanguine");
    cybernetics.push_back("Baleful Eye");
    cybernetics.push_back("Ballistic Mechadendrite");
    cybernetics.push_back("Bionic Arm");
    cybernetics.push_back("Bionic Legs");
    cybernetics.push_back("Bionic Respiratory System");
    cybernetics.push_back("Bionic Heart");
    cybernetics.push_back("Calculus Logi Upgrade");
    cybernetics.push_back("Cybernetic Senses");
    cybernetics.push_back("Ferric Lure Implants");
    cybernetics.push_back("Interface Port");
    cybernetics.push_back("Internal Reservoir");
    cybernetics.push_back("Locator Matrix");
    cybernetics.push_back("Luminen Capacitor");
    cybernetics.push_back("Maglev Coils");
    cybernetics.push_back("Manipulator Mechandendrite");
    cybernetics.push_back("Medicae Mechadendrite");
    cybernetics.push_back("Memorance Implant");
    cybernetics.push_back("Mind Impulse Unit");
    cybernetics.push_back("MIU Weapon Interface");
    cybernetics.push_back("Optical Mechadendrite");
    cybernetics.push_back("Respiratory Filter Implant");
    cybernetics.push_back("Subskin Armor");
    cybernetics.push_back("Synthmuscle");
    cybernetics.push_back("Utility Mechadendrite");
    cybernetics.push_back("Vocal Implant");
    cybernetics.push_back("Volitor Implant");


    std::string statnames[9];
    statnames[WEAPON_SKILL] = "Weapon Skill";
    statnames[BALLISTIC_SKILL] = "Ballistic Skill";
    statnames[STRENGTH] = "Strength";
    statnames[TOUGHNESS] = "Toughness";
    statnames[AGILITY] = "Agility";
    statnames[INTELLIGENCE] = "Intelligence";
    statnames[PERCEPTION] = "Perception";
    statnames[WILLPOWER] = "Willpower";
    statnames[FELLOWSHIP] = "Fellowship";
    int stats[9];
    int fatepoints = 0;
    int totalpoints = 0;
    string demeanor;
    vector <string> demeanorlist;
    demeanorlist.push_back("Addict");
    demeanorlist.push_back("Affable");
    demeanorlist.push_back("Backwater");
    demeanorlist.push_back("Heroic");
    demeanorlist.push_back("Bilious");
    demeanorlist.push_back("Boisterous");
    demeanorlist.push_back("Braggart");
    demeanorlist.push_back("Cocky");
    demeanorlist.push_back("Cook");
    demeanorlist.push_back("Coward");
    demeanorlist.push_back("Death-Wish");
    demeanorlist.push_back("Dissenter");
    demeanorlist.push_back("Dreamer");
    demeanorlist.push_back("Gambler");
    demeanorlist.push_back("Green");
    demeanorlist.push_back("Incompetent");
    demeanorlist.push_back("Jaded");
    demeanorlist.push_back("Joker");
    demeanorlist.push_back("Lateral Thinker");
    demeanorlist.push_back("Loner");
    demeanorlist.push_back("Loose Cannon");
    demeanorlist.push_back("Loyal");
    demeanorlist.push_back("Lucky");
    demeanorlist.push_back("Mentor");
    demeanorlist.push_back("Leech");
    demeanorlist.push_back("Never Bathes");
    demeanorlist.push_back("Nihilist");
    demeanorlist.push_back("Numb");
    demeanorlist.push_back("Oblivious");
    demeanorlist.push_back("Obsessive");
    demeanorlist.push_back("Old");
    demeanorlist.push_back("Optimist");
    demeanorlist.push_back("Pessimist");
    demeanorlist.push_back("Pious");
    demeanorlist.push_back("Psycho");
    demeanorlist.push_back("Quiet");
    demeanorlist.push_back("Reckless");
    demeanorlist.push_back("Sarcastic");
    demeanorlist.push_back("Sensible");
    demeanorlist.push_back("Shell-Shocked");
    demeanorlist.push_back("Slacker");
    demeanorlist.push_back("Slow");
    demeanorlist.push_back("Smooth");
    demeanorlist.push_back("Steely");
    demeanorlist.push_back("Strict");
    demeanorlist.push_back("Superstitious");
    demeanorlist.push_back("Talkative");
    demeanorlist.push_back("Thief");
    demeanorlist.push_back("Twitchy");
    demeanorlist.push_back("Unlucky");

    vector <std::string> classnames;
    classnames.push_back("Heavy Gunner");
    classnames.push_back("Medic");
    classnames.push_back("Operator");
    classnames.push_back("Sergeant");
    classnames.push_back("Weapons Specialist");
    classnames.push_back("Commisar");
    classnames.push_back("Ministorum Priest");
    classnames.push_back("Ogryn");
    classnames.push_back("Ratling");
    classnames.push_back("Sanctioned Psyker");
    classnames.push_back("Storm Trooper");
    classnames.push_back("Tech-Priest Enginseer");

    std::cout << "Input regiment filename or press enter to load default.txt\n";
    char regname[256];
    std::string regfile;
    //cin.getline(regfile, 256);
    std::getline (std::cin, regfile);
    //regfile.append(regname, 256);
    std::size_t floc = regfile.find(".txt");
    if (floc == std::string::npos)
        regfile.append(".txt");

    cout << "attempting to load: " << regfile.c_str() << std::endl;

    if (loadregiment(regfile))
        cout << "File loaded successfully: "  << regfile.c_str() << std::endl;
    else
    {
        cout << "Load failed\nAttempting to load default.txt\n";
        if (loadregiment("default.txt"))
            cout << "default.txt loaded successfully" << std::endl;
        else
            cout << "No regiment file loaded" << std::endl;
    }

    int experience = 0;
    int psykexperience = 0;
    int corruptionpoints = 0;
    bool quit = false;
    while (!quit) //stage 1: Generate Characteristics
    {

        for (int i = 0; i < 9; i++)
        {
            stats[i] = (rand() %10 +1)+(rand() % 10 + 1) + 20;
        }

        for (int i = 0; i < 9; i++)
        {
            std::cout << statnames[i] << " :  " << stats[i] << std::endl;
        }

        for (int i = 0; i < 9; i++)
        {
            totalpoints += stats[i];
        }
        cout << "\nTotalpoints : " << totalpoints << "  (AVG is 279)\n";

        cout << std::endl;
        cout << "Reroll what stat?\n";
        cout << "0: none\n";
        cout << "1: Weapon Skill\n";
        cout << "2: Ballistic Skill\n";
        cout << "3: Strength\n";
        cout << "4: Toughness\n";
        cout << "5: Agility\n";
        cout << "6: Intelligence\n";
        cout << "7: Perception\n";
        cout << "8: Willpower\n";
        cout << "9: Fellowship\n";

        int reroller = 0;
        cin >> reroller;
        if (reroller > 0 && reroller < 10)
        {
            stats[reroller-1] = (rand() %10 +1)+(rand() % 10 + 1) + 20;
        }
        else
        {
            quit = true;
            break;
        }
        for (int i = 0; i < 9; i++)
        {
            std::cout << statnames[i] << " :  " << stats[i] << std::endl;
        }
        totalpoints = 0;
        for (int i = 0; i < 9; i++)
        {
            totalpoints += stats[i];
        }
        cout << std::endl;
        cout << "Totalpoints : " << totalpoints << "  (AVG is 279)\n";
        totalpoints = 0;
        cout << "Roll again? y/n\n";
        char inroll;
        cin >> inroll;
        if (inroll != 'y')
            quit = true;
    }
    quit = false;
    int specialty = 0;
    vector <string> aptitudes;
    vector <string> skills;
    vector <string> talents;
    vector <string> equipment;
    vector <string> traits;
    vector <string> drawbacks;

    vector <STRINGINTCHOICE> statchoices;
    vector <STRINGCHOICE> aptitudechoices;
    vector <STRINGCHOICE> skillchoices;
    vector <STRINGCHOICE> talentchoices;
    vector <STRINGCHOICE> equipmentchoices;
    int wounds = 0;
    int specialtycharmod[9];
    for (int i = 0; i < 9; i++)
        specialtycharmod[i] = 0;

        //add in regiment shit
    /*
    std::string regimentname;
    std::string regimenthomeworld;// = "Viridian";
    std::string regimentworldtype;// = "Agri World";
    std::string regimenttype;// = "Light Infantry";
    std::string regimentofficer;
    int regimentcharmods[10];++++++++++++++++++++++++++++

    std::vector <STRINGINTCHOICE> regimentcharmodopt;+++++++++++++ no tracking yet though

    std::vector <std::string> regimenttalents;+++++++++++++++++++
    std::vector <STRINGCHOICE> regimenttalentsopt; ++++++++++++++++++
    std::vector <std::string> regimentskills;++++++++++++++++++
    std::vector <STRINGCHOICE> regimentskillsopt;
    std::vector <std::string> regimenttraits;++++++++++++++++++
    std::vector <std::string> regimentaptitudes; +++++++++++++++++ need the choice thing
    std::vector <std::string> regimentfavoredbasic;+++++++++++++++?? not for doubles
    std::vector <std::string> regimentfavoredheavy;++++++++++++++++?? not for doubles
    std::vector <std::string> regimentdrawbacks;+++++++++++++++++++++


    std::vector <std::string> regimentequipment;
    */
    //for (unsigned int i = 0; i < regiment.regimentequipment.size(); i++)
    //    talents.push_back(regiment.regimenttalents)

    //for (unsigned int i = 0; i < regiment.regimentequipment.size(); i++)
    //    equipment.push_back(regiment.regimentequipment[i].c_str());

    ///note: aptitude: if have aptitude already, instead you get a main aptitude instead (shares name with skill)
    ///therefore: add the aptidude now. if it comes up doubles later, then offer a choice.

/*
    vector <STRINGINTCHOICE> statchoices;+++++++++++++
    vector <STRINGCHOICE> aptitudechoices; (do later after class pick)
    vector <STRINGCHOICE> skillchoices; (does this ever actually happen from regiment? /shrug)
    vector <STRINGCHOICE> talentchoices;+++++++++++++++
    vector <STRINGCHOICE> equipmentchoices; I'm unsure regiments have equipment choices either
*/
    for (unsigned int i = 0; i < regiment.regimentaptitudes.size(); i++)
        aptitudes.push_back(regiment.regimentaptitudes[i].c_str());
    for (unsigned int i = 0; i < regiment.regimenttalents.size(); i++)
        talents.push_back(regiment.regimenttalents[i].c_str());
    for (unsigned int i = 0; i < regiment.regimentskills.size(); i++)
        skills.push_back(regiment.regimentskills[i].c_str());
    for (unsigned int i = 0; i < regiment.regimentequipment.size(); i++)
        equipment.push_back(regiment.regimentequipment[i].c_str());
    for (unsigned int i = 0; i < regiment.regimenttraits.size(); i++)
        traits.push_back(regiment.regimenttraits[i].c_str());
    for (unsigned int i = 0; i < regiment.regimentdrawbacks.size(); i++)
        drawbacks.push_back(regiment.regimentdrawbacks[i].c_str());
    for (unsigned int i = 0; i < 9; i++) ///wait a minute is this already included somewhere?
        stats[i] += regiment.regimentcharmods[i]; ///no wait, what im seeing is the regiment opt add thing, derp

    for (unsigned int i = 0; i < regiment.regimentcharmodopt.size(); i++)
        statchoices.push_back(regiment.regimentcharmodopt[i]);
    for (unsigned int i = 0; i < regiment.regimenttalentsopt.size(); i++)
        talentchoices.push_back(regiment.regimenttalentsopt[i]);
    for (unsigned int i = 0; i < regiment.regimentskillsopt.size(); i++)
        skillchoices.push_back(regiment.regimentskillsopt[i]);

     //end regiment shit
    while (!quit) //stage 2: choose specialty
    {
        cout << "Choose Specialty\n";
        cout << "GUARDSMEN\n--------------------------\n";
        cout << "1: Heavy Gunner\n";
        cout << "2: Medic\n";
        cout << "3: Operator\n";
        cout << "4: Sergeant\n";
        cout << "5: Weapons Specialist\n";
        cout << "SUPPORT SPECIALISTS\n----------------------\n";
        cout << "6: Commisar\n";
        cout << "7: Ministorum Priest\n";
        cout << "8: Ogryn\n";
        cout << "9: Ratling\n";
        cout << "10: Sanctioned Psyker\n";
        cout << "11: Storm Trooper\n";
        cout << "12: Tech-Priest Enginseer\n";
        cin >> specialty;
        while (specialty <= 0 || specialty > TECH_PRIEST_ENGINSEER)
        {
            cout << "Invalid entry\n";
            cin >> specialty;
        }
        quit = true;
        if (specialty >= 0 && specialty <= WEAPONS_SPECIALIST )
            experience = 600;
        else
            experience = 300;
        int fatepointsroll = rand() %10+1;
        if (fatepointsroll <=7)
            fatepoints = 1;
        else if (fatepointsroll <=9)
            fatepoints = 2;
        else if (fatepointsroll <=10)
            fatepoints = 3;
        switch (specialty)
        {
        case HEAVY_GUNNER:
            {

                wounds = 10+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[TOUGHNESS] = 5;
                aptitudes.push_back("Ballistic Skill");
                aptitudes.push_back("Defence");
                aptitudes.push_back("Fellowship");
                aptitudes.push_back("Offence");
                aptitudes.push_back("Perception");
                aptitudes.push_back("Toughness");

                skills.push_back("Common Lore(Imperial Guard, War)");
                skills.push_back("Intimidate");
                STRINGCHOICE sk1;
                sk1.choices.push_back("Athletics");
                sk1.choices.push_back("Survival");
                skillchoices.push_back(sk1);

                talents.push_back("Iron Jaw");
                talents.push_back("Weapon Training: Low-Tech");
                talents.push_back("Weapon Training: Heavy");
                STRINGCHOICE ta1;
                ta1.choices.push_back("Weapon Training: Las");
                ta1.choices.push_back("Weapon Training: Solid Projectile");
                talentchoices.push_back(ta1);
                STRINGCHOICE ta2;
                for (unsigned int i = 0; i < weapontraining.size(); i++)
                    ta2.choices.push_back(weapontraining[i].c_str());
                talentchoices.push_back(ta2);

                STRINGCHOICE eq1;
                eq1.choices.push_back("Common Craftsmanship Missile launcher + 5 Frag Missiles");
                eq1.choices.push_back("Common Craftsmanship Heavy Stubber");
                string wepchoice = "Common Crafstmanship ";
                wepchoice += regiment.regimentfavoredheavy[0].c_str();
                eq1.choices.push_back(wepchoice.c_str());
                equipmentchoices.push_back(eq1);


            }
            break;
        case MEDIC:
            {
                wounds = 8+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[INTELLIGENCE] = 5;

                aptitudes.push_back("Ballistic Skill");
                aptitudes.push_back("Fieldcraft");
                aptitudes.push_back("Intelligence");
                aptitudes.push_back("Knowledge");
                aptitudes.push_back("Perception");
                aptitudes.push_back("Willpower");

                skills.push_back("Medicae");
                skills.push_back("Scholastic Lore (Chymistry)");

                STRINGCHOICE sk1;
                sk1.choices.push_back("Scrutiny");
                sk1.choices.push_back("Trade (Chymist)");
                skillchoices.push_back(sk1);

                STRINGCHOICE ta1;
                ta1.choices.push_back("Cold Hearted");
                ta1.choices.push_back("Jaded");
                talentchoices.push_back(ta1);
                STRINGCHOICE ta2;
                ta2.choices.push_back("Weapon Training: Las");
                ta2.choices.push_back("Weapon Training: Solid Projectile");
                talentchoices.push_back(ta2);
                talents.push_back("Weapon Training: Low-Tech");

                equipment.push_back("Diagnostor");
                equipment.push_back("Injector");
                equipment.push_back("Medikit");
            }
            break;
        case OPERATOR:
            {
                wounds = 6+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[AGILITY] = 5;

                aptitudes.push_back("Agility");
                aptitudes.push_back("Ballistic Skill");
                aptitudes.push_back("Fellowship");
                aptitudes.push_back("Fieldcraft");
                aptitudes.push_back("Intelligence");
                aptitudes.push_back("Tech");

                STRINGCHOICE sk1;
                sk1.choices.push_back("Common Lore (Tech)");
                sk1.choices.push_back("Navigate (Surface)");
                skillchoices.push_back(sk1);
                skills.push_back("Operate (Surface)");
                skills.push_back("Tech-Use");

                talents.push_back("Technical Knock");
                STRINGCHOICE ta1;
                ta1.choices.push_back("Weapon Training: Las");
                ta1.choices.push_back("Weapon Training: Solid Projectile");
                talents.push_back("Weapon Training: Low-Tech");

                equipment.push_back("Auspex/scanner");
                equipment.push_back("Common Craftsmanship Mind Impulse Unit");
                equipment.push_back("Combi-Tool");
                equipment.push_back("Data-Slate");
                equipment.push_back("Lascutter");


            }
            break;
        case SERGEANT:
            {
                wounds = 10+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[FELLOWSHIP] = 5;

                aptitudes.push_back("Defence");
                aptitudes.push_back("Fellowship");
                aptitudes.push_back("Leadership");
                aptitudes.push_back("Perception");
                aptitudes.push_back("Strength");
                aptitudes.push_back("Toughness");
                aptitudes.push_back("Weapon Skill");

                skills.push_back("Command");
                STRINGCHOICE sk1;
                sk1.choices.push_back("Navigate (Surface)");
                sk1.choices.push_back("Scholastic Lore (Tactica Imperialis)");
                skillchoices.push_back(sk1);

                STRINGCHOICE ta1;
                ta1.choices.push_back("Air of Authority");
                ta1.choices.push_back("Iron Discipline");
                talentchoices.push_back(ta1);
                STRINGCHOICE ta2;
                ta2.choices.push_back("Weapon Training: Las");
                ta2.choices.push_back("Weapon Training: Solid Projectile");
                talentchoices.push_back(ta2);
                talents.push_back("Weapon Training: Chain");
                talents.push_back("Weapon Training: Low-Tech");

                equipment.push_back("Common Craftsmanship Las Pistol");
                equipment.push_back("Common Craftsmanship Chainsword");

            }
            break;
        case WEAPONS_SPECIALIST:
            {
                wounds = 8+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];

                //charmod is a choice between ballistic skill or weapon skill
                STRINGINTCHOICE stc;
                stc.choices.push_back("Ballistic Skill");
                stc.choicesints.push_back(BALLISTIC_SKILL);
                stc.choicesintamount.push_back(5);
                stc.choices.push_back("Weapon Skill");
                stc.choicesints.push_back(WEAPON_SKILL);
                stc.choicesintamount.push_back(5);
                statchoices.push_back(stc);
                regiment.regimentcharmodoptchoicenumber.push_back(0);

                aptitudes.push_back("Agility");
                aptitudes.push_back("Ballistic Skill");
                aptitudes.push_back("Fellowship");
                aptitudes.push_back("Fieldcraft");
                aptitudes.push_back("Finesse");
                aptitudes.push_back("Weapon Skill");

                STRINGCHOICE sk1;
                sk1.choices.push_back("Athletics");
                sk1.choices.push_back("Survival");
                skillchoices.push_back(sk1);
                skills.push_back("Navigate (Surface)");
                skills.push_back("Common Lore (Imperial Guard, War)");

                STRINGCHOICE ta1;
                ta1.choices.push_back("Lasgun Barrage");
                ta1.choices.push_back("Rapid Reload");
                talentchoices.push_back(ta1);
                STRINGCHOICE ta2;
                for (unsigned int i = 0; i < weapontraining.size(); i++)
                { // no heavy
                    if (weapontraining[i].compare("Weapon Training: Heavy") !=0 )
                        ta2.choices.push_back(weapontraining[i].c_str());
                }
                ///pick 3
                talentchoices.push_back(ta2);
                talentchoices.push_back(ta2);
                talentchoices.push_back(ta2);

                STRINGCHOICE eq1;
                eq1.choices.push_back("Frag Grenades, 4");
                eq1.choices.push_back("Krak Grenades, 4");
                equipmentchoices.push_back(eq1);
                STRINGCHOICE eq2;
                eq2.choices.push_back("Good Craftsmanship Lasgun");
                eq2.choices.push_back("Common Craftsmanship Flamer");
                eq2.choices.push_back("Common Craftsmanship Shotgun");
                //eq2.choices.push_back("Common Craftsmanship Flamer");
                string wepchoice = "Common Craftsmanship ";
                wepchoice += regiment.regimentfavoredbasic[0].c_str();
                eq2.choices.push_back(wepchoice.c_str());
                equipmentchoices.push_back(eq2);




            }
            break;
        case COMMISAR:
            {
                wounds = 10+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[FELLOWSHIP] = 5;

                aptitudes.push_back("Agility");
                aptitudes.push_back("Fellowship");
                aptitudes.push_back("Finesse");
                aptitudes.push_back("Leadership");
                aptitudes.push_back("Perception");
                aptitudes.push_back("Weapon Skill");
                aptitudes.push_back("Willpower");

                STRINGCHOICE sk1;
                sk1.choices.push_back("Command");
                sk1.choices.push_back("Intimidate");
                skillchoices.push_back(sk1);
                skills.push_back("Common Lore (Imperial Guard)");
                skills.push_back("Scholastic Lore (Tactica Imperialis)");

                talents.push_back("Air of Authority");
                STRINGCHOICE ta1;
                ta1.choices.push_back("Cold Hearted");
                ta1.choices.push_back("Unshakeable Faith");
                talentchoices.push_back(ta1);
                talents.push_back("Weapon Training: Bolt");
                talents.push_back("Weapon Training: Chain");
                STRINGCHOICE ta2;
                ta2.choices.push_back("Weapon Training: Las");
                ta2.choices.push_back("Weapon Training: Solid Projectile");
                talentchoices.push_back(ta2);

                equipment.push_back("Good Craftsmanship Chainsword");
                equipment.push_back("Good Craftsmanship Bolt Pistol");
                equipment.push_back("Commisar's Uniform");

            }
            break;
        case MINISTORUM_PRIEST:
            {
                wounds = 9+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[FELLOWSHIP] = 5;

                aptitudes.push_back("Fellowship");
                aptitudes.push_back("Leadership");
                aptitudes.push_back("Perception");
                aptitudes.push_back("Social");
                aptitudes.push_back("Strength");
                aptitudes.push_back("Weapon Skill");
                aptitudes.push_back("Willpower");

                STRINGCHOICE sk1;
                sk1.choices.push_back("Charm");
                sk1.choices.push_back("Inquiry");
                skillchoices.push_back(sk1);
                skills.push_back("Common Lore (Ecclesiarchy)");
                skills.push_back("Forbidden Lore (Heresy)");
                skills.push_back("Scholastic Lore (Imperial Creed)");

                STRINGCHOICE ta1;
                ta1.choices.push_back("Hatred: Chaos Space Marines");
                ta1.choices.push_back("Hatred: Daemons");
                ta1.choices.push_back("Hatred: Mutants");
                ta1.choices.push_back("Hatred: Psykers");
                ta1.choices.push_back("Hatred: Xenos-Ork");
                ta1.choices.push_back("Hatred: Xenos-Tau");
                ta1.choices.push_back("Hatred: Xenos-Necron");
                ta1.choices.push_back("Hatred: Xenos-Eldar");
                ta1.choices.push_back("Hatred: Xenos-Dark Eldar");
                ta1.choices.push_back("Hatred: Xenos-Tyranid");
                ta1.choices.push_back("Hatred: (Other)");
                talentchoices.push_back(ta1);
                talents.push_back("Unshakeable Faith");
                talents.push_back("Weapon Training: Chain");
                STRINGCHOICE ta2;
                ta2.choices.push_back("Weapon Training: Las");
                ta2.choices.push_back("Weapon Training: Solid Projectile");
                talentchoices.push_back(ta2);
                talents.push_back("Weapon Training: Flame");
                talents.push_back("Weapon Training: Low-Tech");

                equipment.push_back("Ecclesiarchy Robes");
                equipment.push_back("Common Craftsmanship Flamer");
                equipment.push_back("Common Craftsmanship Chainsword");
                equipment.push_back("Book of Scripture");

            }
            break;
        case OGRYN:
            {
                wounds = 25+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[STRENGTH] = 10;
                specialtycharmod[TOUGHNESS] = 10;
                specialtycharmod[INTELLIGENCE] = -15;
                specialtycharmod[AGILITY] = -10;

                aptitudes.push_back("Ballistic Skill");
                aptitudes.push_back("Defence");
                aptitudes.push_back("Offence");
                aptitudes.push_back("Strength");
                aptitudes.push_back("Toughness");
                aptitudes.push_back("Weapon Skill");

                STRINGCHOICE sk1;
                sk1.choices.push_back("Intimidate");
                sk1.choices.push_back("Survival");
                skillchoices.push_back(sk1);

                STRINGCHOICE ta1;
                ta1.choices.push_back("Die Hard");
                ta1.choices.push_back("Iron Jaw");
                talentchoices.push_back(ta1);
                talents.push_back("Weapon Training: Heavy");
                talents.push_back("Weapon Training: Solid Projectile");

                traits.push_back("Auto-Stabilised");
                traits.push_back("But It Dark in Dere!");
                traits.push_back("Clumsy");
                traits.push_back("Size (Hulking)");
                traits.push_back("Sturdy");
                traits.push_back("Unnatural Strength (+2)");
                traits.push_back("Unnatural Toughness (+2)");

                equipment.push_back("Common Craftsmanship Ripper Gun");
                int randfragnades = rand()%5 +1;
                string nades = "Frag Grenades, ";
                char conv[10];
                itoa(randfragnades, conv, 10);
                nades += conv;
                equipment.push_back(nades.c_str());




            }
            break;
        case RATLING:
            {
                wounds = 5+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[PERCEPTION] = 10;
                specialtycharmod[FELLOWSHIP] = 10;
                specialtycharmod[TOUGHNESS] = -10;

                aptitudes.push_back("Agility");
                aptitudes.push_back("Ballistic Skill");
                aptitudes.push_back("Fellowship");
                aptitudes.push_back("Fieldcraft");
                aptitudes.push_back("Finesse");
                aptitudes.push_back("Perception");
                aptitudes.push_back("Social");

                STRINGCHOICE sk1;
                sk1.choices.push_back("Awareness");
                sk1.choices.push_back("Stealth");
                skillchoices.push_back(sk1);
                skills.push_back("Deceive");
                skills.push_back("Trade (Cook)");

                talents.push_back("Deadeye Shot");
                STRINGCHOICE ta1;
                ta1.choices.push_back("Heightened Senses (Sight, Smell, Taste)");
                ta1.choices.push_back("Light Sleeper");
                talentchoices.push_back(ta1);
                talents.push_back("Weapon Training: Las");
                talents.push_back("Weapon Training: Solid Projectile");

                traits.push_back("Size (Weedy)");

                STRINGCHOICE eq1;
                eq1.choices.push_back("Good Craftsmanship Long-Las");
                eq1.choices.push_back("Good Craftsmanship Snipe Rifle (Telescopic Sight)");
                equipmentchoices.push_back(eq1);
                equipment.push_back("Chameleoline cloak");
                //talents.push_back("Heightened Senses")


            }
            break;
        case SANCTIONED_PSYKER:
            {
                wounds = 8+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[WILLPOWER] = 5;
                psykexperience = 400;
                corruptionpoints = rand() %5 +1;

                aptitudes.push_back("Intelligence");
                aptitudes.push_back("Knowledge");
                aptitudes.push_back("Perception");
                aptitudes.push_back("Psyker");
                aptitudes.push_back("Strength");
                aptitudes.push_back("Willpower");

                skills.push_back("Common Lore (Adeptus Astra Telepathica)");
                skills.push_back("Forbidden Lore (Psykers)");
                skills.push_back("Psyniscience");
                skills.push_back("Scholastic Lore (Cryptology)");

                talents.push_back("Heightened Senses (Hearing)");
                STRINGCHOICE ta1;
                ta1.choices.push_back("Weapon Training: Las");
                ta1.choices.push_back("Weapon Training: Solid Projectile");
                talentchoices.push_back(ta1);
                talents.push_back("Weapon Training: Low-Tech");

                traits.push_back("Psyker");
                traits.push_back("Psy Rating: 2");

                equipment.push_back("Data-Slate");
                equipment.push_back("psy focus");
                equipment.push_back("Best Craftsmanship Staff");



            }
            break;
        case STORM_TROOPER:
            {
                wounds = 12+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[TOUGHNESS] = 5;

                aptitudes.push_back("Agility");
                aptitudes.push_back("Ballistic Skill");
                aptitudes.push_back("Fieldcraft");
                aptitudes.push_back("Finesse");
                aptitudes.push_back("Offence");
                aptitudes.push_back("Toughness");

                skills.push_back("Awareness");
                STRINGCHOICE sk1;
                sk1.choices.push_back("Dodge");
                sk1.choices.push_back("Parry");
                skillchoices.push_back(sk1);
                STRINGCHOICE sk2;
                sk2.choices.push_back("Intimidate");
                sk2.choices.push_back("Security");
                skillchoices.push_back(sk2);
                skills.push_back("Scholastic Lore (Tactica Imperialis)");
                skills.push_back("Stealth");

                STRINGCHOICE ta1;
                ta1.choices.push_back("Quick Draw");
                ta1.choices.push_back("Rapid Reload");
                talentchoices.push_back(ta1);
                talents.push_back("Takedown");
                STRINGCHOICE ta2;
                ta2.choices.push_back("Weapon Training: Las");
                ta2.choices.push_back("Weapon Training: Solid Projectile");
                talentchoices.push_back(ta2);
                talents.push_back("Weapon Training: Low-Tech");

                equipment.push_back("Good Craftsmanship hot-shot Lasgun");
                equipment.push_back("Storm Trooper Carapace Armor");



            }
            break;
        case TECH_PRIEST_ENGINSEER:
            {
                wounds = 8+rand() %5 +1 + regiment.regimentcharmods[WOUNDS];
                specialtycharmod[INTELLIGENCE] = 5;

                aptitudes.push_back("Ballistic Skill");
                aptitudes.push_back("Intelligence");
                aptitudes.push_back("Knowledge");
                aptitudes.push_back("Strength");
                aptitudes.push_back("Tech");
                aptitudes.push_back("Toughness");
                aptitudes.push_back("Weapon Skill");
                aptitudes.push_back("Willpower");

                skills.push_back("Common Lore (Adeptus Mechanicus)");
                skills.push_back("Common Lore (Tech)");
                skills.push_back("Forbidden Lore (Adeptus Mechanicus)");
                STRINGCHOICE sk1;
                sk1.choices.push_back("Forbidden Lore (Archeotech)");
                sk1.choices.push_back("Logic");
                skillchoices.push_back(sk1);
                skills.push_back("Tech-Use");

                STRINGCHOICE ta1;
                ta1.choices.push_back("Cold Hearted");
                ta1.choices.push_back("Technical Knock");
                talentchoices.push_back(ta1);
                talents.push_back("Mechadendrite Use (Weapon, Utility)");
                STRINGCHOICE ta2;
                ta2.choices.push_back("Weapon Training: Las");
                ta2.choices.push_back("Weapon Training: Solid Projectile");
                talentchoices.push_back(ta2);
                talents.push_back("Weapon Training: Power");

                traits.push_back("Mechanicus Implants");

                equipment.push_back("Sacred Unguents");
                equipment.push_back("Dataslate");
                equipment.push_back("Combi-tool");
                //one utility or ballistic mechadendrite of choice
                STRINGCHOICE eq1;
                eq1.choices.push_back("Good Craftsmanship Ballistic Mechadendrite");
                eq1.choices.push_back("Good Craftsmanship Utility Mechadendrite");
                equipmentchoices.push_back(eq1);
                equipment.push_back("Good Craftsmanship Mind Impulse Unit");
                //two good craftsmanship cybernetics of choice
                STRINGCHOICE eq2;
                string qualitype = "Good Craftsmanship ";
                for (unsigned int i = 0; i < cybernetics.size(); i++)
                {
                    string qt = qualitype;
                    eq2.choices.push_back(qt.append(cybernetics[i]).c_str());
                }
                equipmentchoices.push_back(eq2);
                equipmentchoices.push_back(eq2);

            }
            break;

        }

    }


    quit = false;
    while (!quit)
    {
        if (statchoices.size() <1)
            break;


        for (unsigned int i = 0; i < statchoices.size(); i++)
        {
            //check choices and stuff to make sure it lines up
            if (regiment.regimentcharmodoptchoicenumber[i] > statchoices[i].choices.size())
                regiment.regimentcharmodoptchoicenumber[i] = statchoices[i].choices.size();
            for (unsigned int choices = 0; choices <= regiment.regimentcharmodoptchoicenumber[i]; choices++)
            {
                cout << "Choose Stat\n";
                cout << "Choices number is " << choices+1 << " of " << regiment.regimentcharmodoptchoicenumber[i]+1 << std::endl;
                //cout << "btw statchoice size is: " << statchoices.size() << std::endl;
                for (unsigned int j = 0; j < statchoices[i].choices.size(); j++)
                {
                    cout << j << ": " << statchoices[i].choices[j].c_str() << "  +" << statchoices[i].choicesintamount[j] << endl;
                }
                unsigned int choice = 0;
                cin >> choice;
                while (choice > statchoices[i].choices.size()-1)
                {
                    cout << "Invalid entry\n";
                    cin >> choice;
                }
                cout << statchoices[i].choices[choice].c_str() << " chosen\n";
                //aptitudes.push_back(aptitudechoices[i].choices[choice].c_str());
                //stats[statchoices[i].choicesints[choice]] += statchoices[i].choicesintamount[choice];
                specialtycharmod[statchoices[i].choicesints[choice]] += statchoices[i].choicesintamount[choice];
                //reparse the list because there may be choices left
                statchoices[i].choices.erase(statchoices[i].choices.begin()+choice);
                statchoices[i].choicesints.erase(statchoices[i].choicesints.begin()+choice);
                statchoices[i].choicesintamount.erase(statchoices[i].choicesintamount.begin()+choice);

                //cout << "choices is: " << choices << " vs amount to go" << regiment.regimentcharmodoptchoicenumber[i] << std::endl;


            }

        }
        quit = true;
    }
    quit = false;
    unsigned int demeanorchoice = rand() %50;
    if (demeanorchoice < demeanorlist.size())
    {
        demeanor = demeanorlist[demeanorchoice].c_str();
    }
    else
        demeanor = "No Demeanor Found";

    for (int i = 0; i < 9; i++)
        stats[i] += specialtycharmod[i];


    cout << endl;
    cout << classnames[specialty-1].c_str() << endl;
    //cout << endl;
    cout << "APTITUDES:\n";
    for (unsigned int i = 0; i < aptitudes.size(); i++)
        cout << aptitudes[i].c_str() << endl;
    cout << "SKILLS:\n";
    for (unsigned int i = 0; i < skills.size(); i++)
        cout << skills[i].c_str() << endl;
    cout << "TALENTS:\n";
    for (unsigned int i = 0; i < talents.size(); i++)
        cout << talents[i].c_str() << endl;
    if (traits.size()>0)
    {
        cout << "TRAITS:\n";
        for (unsigned int i = 0; i < traits.size(); i++)
            cout << traits[i].c_str() << endl;
    }
    cout << "EQUIPMENT:\n";
    for (unsigned int i = 0; i < equipment.size(); i++)
        cout << equipment[i].c_str() << endl;

    cout << endl;
    cout << "Total Stats:\n";
    for (int i = 0; i < 9; i++)
    {
        std::cout << statnames[i] << " :  " << stats[i];
        if (specialtycharmod[i]>0)
        {
            cout << "  (Specialty adds " << specialtycharmod[i] << " and is included)";
        }
        if (specialtycharmod[i]<0)
        {
            cout << "  (Specialty subtracts " << specialtycharmod[i] << " and is included)";
        }
        cout << std::endl;
    }
    cout << "Wounds total: " << wounds;
    if (regiment.regimentcharmods[WOUNDS]>0)
    {
        cout << "  (Regiment adds " << regiment.regimentcharmods[WOUNDS] << " and is included)";
    }
    cout << endl;
    cout << "Fate total: " << fatepoints << endl;
    cout << "Demeanor: " << demeanor.c_str() << endl;
    if (corruptionpoints > 0)
        cout << "Corruption Points: " << corruptionpoints << endl;
    cout << "Total Experience to Spend: " << experience;
    if (psykexperience > 0)
        cout << "  (and " << psykexperience << " Psyk experience)";
    cout << endl;

    quit = false;

    while (!quit)
    {
        if (aptitudechoices.size() <1)
            break;
        for (unsigned int i = 0; i < aptitudechoices.size(); i++)
        {
            cout << "Choose Aptitudes\n";
            for (unsigned int j = 0; j < aptitudechoices[i].choices.size(); j++)
            {
                cout << j << ": " << aptitudechoices[i].choices[j].c_str() << endl;
            }
            unsigned int choice = 0;
            cin >> choice;
            while (choice > aptitudechoices[i].choices.size()-1)
            {
                cout << "Invalid entry\n";
                cin >> choice;
            }
            cout << aptitudechoices[i].choices[choice].c_str() << " chosen\n";
            aptitudes.push_back(aptitudechoices[i].choices[choice].c_str());
        }
        quit = true;
    }
    quit = false;
    while (!quit)
    {
        cout << endl;
        skillbreak:
        if (skillchoices.size() <1)
            break;
        for (unsigned int i = 0; i < skillchoices.size(); i++)
        {

            for (unsigned int el = 0; el < skillchoices[i].choices.size(); el++)
            {
                for (unsigned int scomp = 0; scomp < skills.size(); scomp++)
                {
                    if (skills[scomp].compare(skillchoices[i].choices[el]) == 0)
                    {
                        //cout << "Erasing " << talentchoices[i].choices[el].c_str() << endl;
                        skillchoices[i].choices.erase(skillchoices[i].choices.begin()+el);
                        goto skillbreak;
                    }

                }
            }
            if (skillchoices[i].choices.size() == 1)
            {
                skills.push_back(skillchoices[i].choices[0].c_str());
                continue;
            }
            if (skillchoices[i].choices.size()<)
                break;
            cout << "Choose Skills\n";
            for (unsigned int j = 0; j < skillchoices[i].choices.size(); j++)
            {
                cout << j << ": " << skillchoices[i].choices[j].c_str() << endl;
            }
            unsigned int choice = 0;
            cin >> choice;
            while (choice > skillchoices[i].choices.size()-1)
            {
                cout << "Invalid entry\n";
                cin >> choice;
            }
            cout << skillchoices[i].choices[choice].c_str() << " chosen\n";
            skills.push_back(skillchoices[i].choices[choice].c_str());
        }
        quit = true;
    }
    quit = false;
    while (!quit)
    {
        cout << endl;
        if (talentchoices.size() <1)
            break;
        for (unsigned int i = 0; i < talentchoices.size(); i++)
        {
            //eliminate already chosen talents
            talentbreak:
            for (unsigned int el = 0; el < talentchoices[i].choices.size(); el++)
            {
                for (unsigned int tcomp = 0; tcomp < talents.size(); tcomp++)
                {
                    if (talents[tcomp].compare(talentchoices[i].choices[el]) == 0)
                    {
                        //cout << "Erasing " << talentchoices[i].choices[el].c_str() << endl;
                        talentchoices[i].choices.erase(talentchoices[i].choices.begin()+el);
                        goto talentbreak;
                    }

                }
            }
            cout << "Choose Talents\n";
            for (unsigned int j = 0; j < talentchoices[i].choices.size(); j++)
            {
                cout << j << ": " << talentchoices[i].choices[j].c_str() << endl;
            }
            unsigned int choice = 0;
            cin >> choice;
            while (choice > talentchoices[i].choices.size()-1)
            {
                cout << "Invalid entry\n";
                cin >> choice;
            }
            cout << talentchoices[i].choices[choice].c_str() << " chosen\n";
            talents.push_back(talentchoices[i].choices[choice].c_str());
        }
        quit = true;
    }
    quit = false;
    while (!quit)
    {
        cout << endl;
        if (equipmentchoices.size() <1)
            break;
        for (unsigned int i = 0; i < equipmentchoices.size(); i++)
        {
            cout << "Choose Equipment\n";
            for (unsigned int j = 0; j < equipmentchoices[i].choices.size(); j++)
            {
                cout << j << ": " << equipmentchoices[i].choices[j].c_str() << endl;
            }
            unsigned int choice = 0;
            cin >> choice;
            while (choice > equipmentchoices[i].choices.size()-1)
            {
                cout << "Invalid entry\n";
                cin >> choice;
            }
            cout << equipmentchoices[i].choices[choice].c_str() << " chosen\n";
            equipment.push_back(equipmentchoices[i].choices[choice].c_str());
        }
        quit = true;
    }
    quit = false;

    //output to file
    ofstream outfile;
    outfile.open("CharacterSave.txt");
    outfile << classnames[specialty-1].c_str() << endl;
    for (unsigned int i = 0; i < 9; i++)
    {
        outfile << statnames[i] << ": " << stats[i] << endl;
    }
    outfile << "Wounds: " << wounds << endl;
    outfile << "Fate: " << fatepoints << endl;
    outfile << "Demeanor: " << demeanor.c_str() << endl;
    outfile << "Exp (unspent): " << experience << endl;
    if (psykexperience > 0)
        outfile << "Psyker Exp (unspent): " << psykexperience << endl;
    if (corruptionpoints > 0)
        outfile << "Corruption Points: " << corruptionpoints << endl;
    outfile << endl;
    outfile << "APTITUDES:\n";
    for (unsigned int i = 0; i < aptitudes.size(); i++)
        outfile << aptitudes[i].c_str() << endl;
    outfile << endl;
    outfile << "SKILLS:\n";
    for (unsigned int i = 0; i < skills.size(); i++)
        outfile << skills[i].c_str() << endl;
    outfile << endl;
    outfile << "TALENTS:\n";
    for (unsigned int i = 0; i < talents.size(); i++)
        outfile << talents[i].c_str() << endl;
    outfile << endl;
    if (traits.size()>0)
    {
        outfile << "Traits:\n";
        for (unsigned int i = 0; i < traits.size(); i++)
            outfile << traits[i].c_str() << endl;
        outfile << endl;

    }
    outfile << "EQUIPMENT:\n";
    for (unsigned int i = 0; i < equipment.size(); i++)
        outfile << equipment[i].c_str() << endl;

    outfile.close();
    cout << endl;
    cout << "Outputted saved character to: CharacterSave.txt";

    return 0;
}
