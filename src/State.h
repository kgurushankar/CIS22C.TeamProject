#pragma once
/** State class for storing state and perform data validation
 * author : Keshav Gurushankar
 */

#ifndef STATE_H
#define STATE_H

#include <iostream>

using std::string;
using std::ostream;

enum Option
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
	Option s;

public:
	State(string s);
	State() { s; }
	string toString();
	int toInt();
	bool operator==(const State &o) { return this->s == o.s; }
	bool operator!=(const State &o) { return this->s != o.s; }
	friend ostream &operator<<(ostream &, State &);
};

State::State(string str)
{
	if (str == "AL")
	{
		this->s = Option::AL;
	}
	else if (str == "AK")
	{
		this->s = Option::AK;
	}
	else if (str == "AS")
	{
		this->s = Option::AS;
	}
	else if (str == "AZ")
	{
		this->s = Option::AZ;
	}
	else if (str == "AR")
	{
		this->s = Option::AR;
	}
	else if (str == "CA")
	{
		this->s = Option::CA;
	}
	else if (str == "CO")
	{
		this->s = Option::CO;
	}
	else if (str == "CT")
	{
		this->s = Option::CT;
	}
	else if (str == "DE")
	{
		this->s = Option::DE;
	}
	else if (str == "DC")
	{
		this->s = Option::DC;
	}
	else if (str == "FL")
	{
		this->s = Option::FL;
	}
	else if (str == "GA")
	{
		this->s = Option::GA;
	}
	else if (str == "GU")
	{
		this->s = Option::GU;
	}
	else if (str == "HI")
	{
		this->s = Option::HI;
	}
	else if (str == "ID")
	{
		this->s = Option::ID;
	}
	else if (str == "IL")
	{
		this->s = Option::IL;
	}
	else if (str == "IN")
	{
		this->s = Option::IN;
	}
	else if (str == "IA")
	{
		this->s = Option::IA;
	}
	else if (str == "KS")
	{
		this->s = Option::KS;
	}
	else if (str == "KY")
	{
		this->s = Option::KY;
	}
	else if (str == "LA")
	{
		this->s = Option::LA;
	}
	else if (str == "ME")
	{
		this->s = Option::ME;
	}
	else if (str == "MD")
	{
		this->s = Option::MD;
	}
	else if (str == "MH")
	{
		this->s = Option::MH;
	}
	else if (str == "MA")
	{
		this->s = Option::MA;
	}
	else if (str == "MI")
	{
		this->s = Option::MI;
	}
	else if (str == "FM")
	{
		this->s = Option::FM;
	}
	else if (str == "MN")
	{
		this->s = Option::MN;
	}
	else if (str == "MS")
	{
		this->s = Option::MS;
	}
	else if (str == "MO")
	{
		this->s = Option::MO;
	}
	else if (str == "MT")
	{
		this->s = Option::MT;
	}
	else if (str == "NE")
	{
		this->s = Option::NE;
	}
	else if (str == "NV")
	{
		this->s = Option::NV;
	}
	else if (str == "NH")
	{
		this->s = Option::NH;
	}
	else if (str == "NJ")
	{
		this->s = Option::NJ;
	}
	else if (str == "NM")
	{
		this->s = Option::NM;
	}
	else if (str == "NY")
	{
		this->s = Option::NY;
	}
	else if (str == "NC")
	{
		this->s = Option::NC;
	}
	else if (str == "ND")
	{
		this->s = Option::ND;
	}
	else if (str == "MP")
	{
		this->s = Option::MP;
	}
	else if (str == "OH")
	{
		this->s = Option::OH;
	}
	else if (str == "OK")
	{
		this->s = Option::OK;
	}
	else if (str == "OR")
	{
		this->s = Option::OR;
	}
	else if (str == "PW")
	{
		this->s = Option::PW;
	}
	else if (str == "PA")
	{
		this->s = Option::PA;
	}
	else if (str == "PR")
	{
		this->s = Option::PR;
	}
	else if (str == "RI")
	{
		this->s = Option::RI;
	}
	else if (str == "SC")
	{
		this->s = Option::SC;
	}
	else if (str == "SD")
	{
		this->s = Option::SD;
	}
	else if (str == "TN")
	{
		this->s = Option::TN;
	}
	else if (str == "TX")
	{
		this->s = Option::TX;
	}
	else if (str == "UT")
	{
		this->s = Option::UT;
	}
	else if (str == "VT")
	{
		this->s = Option::VT;
	}
	else if (str == "VA")
	{
		this->s = Option::VA;
	}
	else if (str == "VI")
	{
		this->s = Option::VI;
	}
	else if (str == "WA")
	{
		this->s = Option::WA;
	}
	else if (str == "WV")
	{
		this->s = Option::WV;
	}
	else if (str == "WI")
	{
		this->s = Option::WI;
	}
	else if (str == "WY")
	{
		this->s = Option::WY;
	}
	else
	{
		throw std::invalid_argument(str + " is not a valid state");
	}
}

string State::toString()
{
	if (this->s == Option::AL)
		return "AL";
	else if (this->s == Option::AK)
		return "AK";
	else if (this->s == Option::AS)
		return "AS";
	else if (this->s == Option::AZ)
		return "AZ";
	else if (this->s == Option::AR)
		return "AR";
	else if (this->s == Option::CA)
		return "CA";
	else if (this->s == Option::CO)
		return "CO";
	else if (this->s == Option::CT)
		return "CT";
	else if (this->s == Option::DE)
		return "DE";
	else if (this->s == Option::DC)
		return "DC";
	else if (this->s == Option::FL)
		return "FL";
	else if (this->s == Option::GA)
		return "GA";
	else if (this->s == Option::GU)
		return "GU";
	else if (this->s == Option::HI)
		return "HI";
	else if (this->s == Option::ID)
		return "ID";
	else if (this->s == Option::IL)
		return "IL";
	else if (this->s == Option::IN)
		return "IN";
	else if (this->s == Option::IA)
		return "IA";
	else if (this->s == Option::KS)
		return "KS";
	else if (this->s == Option::KY)
		return "KY";
	else if (this->s == Option::LA)
		return "LA";
	else if (this->s == Option::ME)
		return "ME";
	else if (this->s == Option::MD)
		return "MD";
	else if (this->s == Option::MH)
		return "MH";
	else if (this->s == Option::MA)
		return "MA";
	else if (this->s == Option::MI)
		return "MI";
	else if (this->s == Option::FM)
		return "FM";
	else if (this->s == Option::MN)
		return "MN";
	else if (this->s == Option::MS)
		return "MS";
	else if (this->s == Option::MO)
		return "MO";
	else if (this->s == Option::MT)
		return "MT";
	else if (this->s == Option::NE)
		return "NE";
	else if (this->s == Option::NV)
		return "NV";
	else if (this->s == Option::NH)
		return "NH";
	else if (this->s == Option::NJ)
		return "NJ";
	else if (this->s == Option::NM)
		return "NM";
	else if (this->s == Option::NY)
		return "NY";
	else if (this->s == Option::NC)
		return "NC";
	else if (this->s == Option::ND)
		return "ND";
	else if (this->s == Option::MP)
		return "MP";
	else if (this->s == Option::OH)
		return "OH";
	else if (this->s == Option::OK)
		return "OK";
	else if (this->s == Option::OR)
		return "OR";
	else if (this->s == Option::PW)
		return "PW";
	else if (this->s == Option::PA)
		return "PA";
	else if (this->s == Option::PR)
		return "PR";
	else if (this->s == Option::RI)
		return "RI";
	else if (this->s == Option::SC)
		return "SC";
	else if (this->s == Option::SD)
		return "SD";
	else if (this->s == Option::TN)
		return "TN";
	else if (this->s == Option::TX)
		return "TX";
	else if (this->s == Option::UT)
		return "UT";
	else if (this->s == Option::VT)
		return "VT";
	else if (this->s == Option::VA)
		return "VA";
	else if (this->s == Option::VI)
		return "VI";
	else if (this->s == Option::WA)
		return "WA";
	else if (this->s == Option::WV)
		return "WV";
	else if (this->s == Option::WI)
		return "WI";
	else if (this->s == Option::WY)
		return "WY";
	else
		return "";
}

int State::toInt()
{
	if (this->s == Option::AL)
		return 0;
	else if (this->s == Option::AK)
		return 1;
	else if (this->s == Option::AS)
		return 2;
	else if (this->s == Option::AZ)
		return 3;
	else if (this->s == Option::AR)
		return 4;
	else if (this->s == Option::CA)
		return 5;
	else if (this->s == Option::CO)
		return 6;
	else if (this->s == Option::CT)
		return 7;
	else if (this->s == Option::DE)
		return 8;
	else if (this->s == Option::DC)
		return 9;
	else if (this->s == Option::FL)
		return 10;
	else if (this->s == Option::GA)
		return 11;
	else if (this->s == Option::GU)
		return 12;
	else if (this->s == Option::HI)
		return 13;
	else if (this->s == Option::ID)
		return 14;
	else if (this->s == Option::IL)
		return 15;
	else if (this->s == Option::IN)
		return 16;
	else if (this->s == Option::IA)
		return 17;
	else if (this->s == Option::KS)
		return 18;
	else if (this->s == Option::KY)
		return 19;
	else if (this->s == Option::LA)
		return 20;
	else if (this->s == Option::ME)
		return 21;
	else if (this->s == Option::MD)
		return 22;
	else if (this->s == Option::MH)
		return 23;
	else if (this->s == Option::MA)
		return 24;
	else if (this->s == Option::MI)
		return 25;
	else if (this->s == Option::FM)
		return 26;
	else if (this->s == Option::MN)
		return 27;
	else if (this->s == Option::MS)
		return 28;
	else if (this->s == Option::MO)
		return 29;
	else if (this->s == Option::MT)
		return 30;
	else if (this->s == Option::NE)
		return 31;
	else if (this->s == Option::NV)
		return 32;
	else if (this->s == Option::NH)
		return 33;
	else if (this->s == Option::NJ)
		return 34;
	else if (this->s == Option::NM)
		return 35;
	else if (this->s == Option::NY)
		return 36;
	else if (this->s == Option::NC)
		return 37;
	else if (this->s == Option::ND)
		return 38;
	else if (this->s == Option::MP)
		return 39;
	else if (this->s == Option::OH)
		return 40;
	else if (this->s == Option::OK)
		return 41;
	else if (this->s == Option::OR)
		return 42;
	else if (this->s == Option::PW)
		return 43;
	else if (this->s == Option::PA)
		return 44;
	else if (this->s == Option::PR)
		return 45;
	else if (this->s == Option::RI)
		return 46;
	else if (this->s == Option::SC)
		return 47;
	else if (this->s == Option::SD)
		return 48;
	else if (this->s == Option::TN)
		return 49;
	else if (this->s == Option::TX)
		return 50;
	else if (this->s == Option::UT)
		return 51;
	else if (this->s == Option::VT)
		return 52;
	else if (this->s == Option::VA)
		return 53;
	else if (this->s == Option::VI)
		return 54;
	else if (this->s == Option::WA)
		return 55;
	else if (this->s == Option::WV)
		return 56;
	else if (this->s == Option::WI)
		return 57;
	else if (this->s == Option::WY)
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