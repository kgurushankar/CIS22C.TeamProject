/** State class for storing state and perform data validation
 * author : Keshav Gurushankar
 */
#ifndef STATE_H
#define STATE_H
#include <iostream>
using std::ostream;
using std::string;
enum StateOption
{
	AL,
	AK,
	AS,
	AZ,
	AR,
	CA,
	CO,
	CT,
	DE,
	DC,
	FL,
	GA,
	GU,
	HI,
	ID,
	IL,
	IN,
	IA,
	KS,
	KY,
	LA,
	ME,
	MD,
	MH,
	MA,
	MI,
	FM,
	MN,
	MS,
	MO,
	MT,
	NE,
	NV,
	NH,
	NJ,
	NM,
	NY,
	NC,
	ND,
	MP,
	OH,
	OK,
	OR,
	PW,
	PA,
	PR,
	RI,
	SC,
	SD,
	TN,
	TX,
	UT,
	VT,
	VA,
	VI,
	WA,
	WV,
	WI,
	WY
};
class State
{
private:
	StateOption s;

public:
	State(string str);
	State() { s; }
	string toString();
	int toInt();
	bool operator==(State &o) { return this->s == o.s; }
	bool operator!=(State &o) { return this->s != o.s; }
	friend ostream &operator<<(ostream &, State &);
};
State::State(string str)
{
	if (str == "AL")
		this->s = StateOption::AL;
	else if (str == "AK")
		this->s = StateOption::AK;
	else if (str == "AS")
		this->s = StateOption::AS;
	else if (str == "AZ")
		this->s = StateOption::AZ;
	else if (str == "AR")
		this->s = StateOption::AR;
	else if (str == "CA")
		this->s = StateOption::CA;
	else if (str == "CO")
		this->s = StateOption::CO;
	else if (str == "CT")
		this->s = StateOption::CT;
	else if (str == "DE")
		this->s = StateOption::DE;
	else if (str == "DC")
		this->s = StateOption::DC;
	else if (str == "FL")
		this->s = StateOption::FL;
	else if (str == "GA")
		this->s = StateOption::GA;
	else if (str == "GU")
		this->s = StateOption::GU;
	else if (str == "HI")
		this->s = StateOption::HI;
	else if (str == "ID")
		this->s = StateOption::ID;
	else if (str == "IL")
		this->s = StateOption::IL;
	else if (str == "IN")
		this->s = StateOption::IN;
	else if (str == "IA")
		this->s = StateOption::IA;
	else if (str == "KS")
		this->s = StateOption::KS;
	else if (str == "KY")
		this->s = StateOption::KY;
	else if (str == "LA")
		this->s = StateOption::LA;
	else if (str == "ME")
		this->s = StateOption::ME;
	else if (str == "MD")
		this->s = StateOption::MD;
	else if (str == "MH")
		this->s = StateOption::MH;
	else if (str == "MA")
		this->s = StateOption::MA;
	else if (str == "MI")
		this->s = StateOption::MI;
	else if (str == "FM")
		this->s = StateOption::FM;
	else if (str == "MN")
		this->s = StateOption::MN;
	else if (str == "MS")
		this->s = StateOption::MS;
	else if (str == "MO")
		this->s = StateOption::MO;
	else if (str == "MT")
		this->s = StateOption::MT;
	else if (str == "NE")
		this->s = StateOption::NE;
	else if (str == "NV")
		this->s = StateOption::NV;
	else if (str == "NH")
		this->s = StateOption::NH;
	else if (str == "NJ")
		this->s = StateOption::NJ;
	else if (str == "NM")
		this->s = StateOption::NM;
	else if (str == "NY")
		this->s = StateOption::NY;
	else if (str == "NC")
		this->s = StateOption::NC;
	else if (str == "ND")
		this->s = StateOption::ND;
	else if (str == "MP")
		this->s = StateOption::MP;
	else if (str == "OH")
		this->s = StateOption::OH;
	else if (str == "OK")
		this->s = StateOption::OK;
	else if (str == "OR")
		this->s = StateOption::OR;
	else if (str == "PW")
		this->s = StateOption::PW;
	else if (str == "PA")
		this->s = StateOption::PA;
	else if (str == "PR")
		this->s = StateOption::PR;
	else if (str == "RI")
		this->s = StateOption::RI;
	else if (str == "SC")
		this->s = StateOption::SC;
	else if (str == "SD")
		this->s = StateOption::SD;
	else if (str == "TN")
		this->s = StateOption::TN;
	else if (str == "TX")
		this->s = StateOption::TX;
	else if (str == "UT")
		this->s = StateOption::UT;
	else if (str == "VT")
		this->s = StateOption::VT;
	else if (str == "VA")
		this->s = StateOption::VA;
	else if (str == "VI")
		this->s = StateOption::VI;
	else if (str == "WA")
		this->s = StateOption::WA;
	else if (str == "WV")
		this->s = StateOption::WV;
	else if (str == "WI")
		this->s = StateOption::WI;
	else if (str == "WY")
		this->s = StateOption::WY;
	else
		throw std::invalid_argument(str + " is not a valid state");
}
string State::toString()
{
	if (this->s == StateOption::AL)
		return "AL";
	else if (this->s == StateOption::AK)
		return "AK";
	else if (this->s == StateOption::AS)
		return "AS";
	else if (this->s == StateOption::AZ)
		return "AZ";
	else if (this->s == StateOption::AR)
		return "AR";
	else if (this->s == StateOption::CA)
		return "CA";
	else if (this->s == StateOption::CO)
		return "CO";
	else if (this->s == StateOption::CT)
		return "CT";
	else if (this->s == StateOption::DE)
		return "DE";
	else if (this->s == StateOption::DC)
		return "DC";
	else if (this->s == StateOption::FL)
		return "FL";
	else if (this->s == StateOption::GA)
		return "GA";
	else if (this->s == StateOption::GU)
		return "GU";
	else if (this->s == StateOption::HI)
		return "HI";
	else if (this->s == StateOption::ID)
		return "ID";
	else if (this->s == StateOption::IL)
		return "IL";
	else if (this->s == StateOption::IN)
		return "IN";
	else if (this->s == StateOption::IA)
		return "IA";
	else if (this->s == StateOption::KS)
		return "KS";
	else if (this->s == StateOption::KY)
		return "KY";
	else if (this->s == StateOption::LA)
		return "LA";
	else if (this->s == StateOption::ME)
		return "ME";
	else if (this->s == StateOption::MD)
		return "MD";
	else if (this->s == StateOption::MH)
		return "MH";
	else if (this->s == StateOption::MA)
		return "MA";
	else if (this->s == StateOption::MI)
		return "MI";
	else if (this->s == StateOption::FM)
		return "FM";
	else if (this->s == StateOption::MN)
		return "MN";
	else if (this->s == StateOption::MS)
		return "MS";
	else if (this->s == StateOption::MO)
		return "MO";
	else if (this->s == StateOption::MT)
		return "MT";
	else if (this->s == StateOption::NE)
		return "NE";
	else if (this->s == StateOption::NV)
		return "NV";
	else if (this->s == StateOption::NH)
		return "NH";
	else if (this->s == StateOption::NJ)
		return "NJ";
	else if (this->s == StateOption::NM)
		return "NM";
	else if (this->s == StateOption::NY)
		return "NY";
	else if (this->s == StateOption::NC)
		return "NC";
	else if (this->s == StateOption::ND)
		return "ND";
	else if (this->s == StateOption::MP)
		return "MP";
	else if (this->s == StateOption::OH)
		return "OH";
	else if (this->s == StateOption::OK)
		return "OK";
	else if (this->s == StateOption::OR)
		return "OR";
	else if (this->s == StateOption::PW)
		return "PW";
	else if (this->s == StateOption::PA)
		return "PA";
	else if (this->s == StateOption::PR)
		return "PR";
	else if (this->s == StateOption::RI)
		return "RI";
	else if (this->s == StateOption::SC)
		return "SC";
	else if (this->s == StateOption::SD)
		return "SD";
	else if (this->s == StateOption::TN)
		return "TN";
	else if (this->s == StateOption::TX)
		return "TX";
	else if (this->s == StateOption::UT)
		return "UT";
	else if (this->s == StateOption::VT)
		return "VT";
	else if (this->s == StateOption::VA)
		return "VA";
	else if (this->s == StateOption::VI)
		return "VI";
	else if (this->s == StateOption::WA)
		return "WA";
	else if (this->s == StateOption::WV)
		return "WV";
	else if (this->s == StateOption::WI)
		return "WI";
	else if (this->s == StateOption::WY)
		return "WY";
	else
		return "";
}
int State::toInt()
{
	if (this->s == StateOption::AL)
		return 0;
	else if (this->s == StateOption::AK)
		return 1;
	else if (this->s == StateOption::AS)
		return 2;
	else if (this->s == StateOption::AZ)
		return 3;
	else if (this->s == StateOption::AR)
		return 4;
	else if (this->s == StateOption::CA)
		return 5;
	else if (this->s == StateOption::CO)
		return 6;
	else if (this->s == StateOption::CT)
		return 7;
	else if (this->s == StateOption::DE)
		return 8;
	else if (this->s == StateOption::DC)
		return 9;
	else if (this->s == StateOption::FL)
		return 10;
	else if (this->s == StateOption::GA)
		return 11;
	else if (this->s == StateOption::GU)
		return 12;
	else if (this->s == StateOption::HI)
		return 13;
	else if (this->s == StateOption::ID)
		return 14;
	else if (this->s == StateOption::IL)
		return 15;
	else if (this->s == StateOption::IN)
		return 16;
	else if (this->s == StateOption::IA)
		return 17;
	else if (this->s == StateOption::KS)
		return 18;
	else if (this->s == StateOption::KY)
		return 19;
	else if (this->s == StateOption::LA)
		return 20;
	else if (this->s == StateOption::ME)
		return 21;
	else if (this->s == StateOption::MD)
		return 22;
	else if (this->s == StateOption::MH)
		return 23;
	else if (this->s == StateOption::MA)
		return 24;
	else if (this->s == StateOption::MI)
		return 25;
	else if (this->s == StateOption::FM)
		return 26;
	else if (this->s == StateOption::MN)
		return 27;
	else if (this->s == StateOption::MS)
		return 28;
	else if (this->s == StateOption::MO)
		return 29;
	else if (this->s == StateOption::MT)
		return 30;
	else if (this->s == StateOption::NE)
		return 31;
	else if (this->s == StateOption::NV)
		return 32;
	else if (this->s == StateOption::NH)
		return 33;
	else if (this->s == StateOption::NJ)
		return 34;
	else if (this->s == StateOption::NM)
		return 35;
	else if (this->s == StateOption::NY)
		return 36;
	else if (this->s == StateOption::NC)
		return 37;
	else if (this->s == StateOption::ND)
		return 38;
	else if (this->s == StateOption::MP)
		return 39;
	else if (this->s == StateOption::OH)
		return 40;
	else if (this->s == StateOption::OK)
		return 41;
	else if (this->s == StateOption::OR)
		return 42;
	else if (this->s == StateOption::PW)
		return 43;
	else if (this->s == StateOption::PA)
		return 44;
	else if (this->s == StateOption::PR)
		return 45;
	else if (this->s == StateOption::RI)
		return 46;
	else if (this->s == StateOption::SC)
		return 47;
	else if (this->s == StateOption::SD)
		return 48;
	else if (this->s == StateOption::TN)
		return 49;
	else if (this->s == StateOption::TX)
		return 50;
	else if (this->s == StateOption::UT)
		return 51;
	else if (this->s == StateOption::VT)
		return 52;
	else if (this->s == StateOption::VA)
		return 53;
	else if (this->s == StateOption::VI)
		return 54;
	else if (this->s == StateOption::WA)
		return 55;
	else if (this->s == StateOption::WV)
		return 56;
	else if (this->s == StateOption::WI)
		return 57;
	else if (this->s == StateOption::WY)
		return 58;
	else
		return -1;
}
ostream &operator<<(ostream &out, State &a)
{
	out << a.toString();
	return out;
}
#endif