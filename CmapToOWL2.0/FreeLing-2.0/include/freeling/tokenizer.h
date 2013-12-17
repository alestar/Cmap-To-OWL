//////////////////////////////////////////////////////////////////
//
//    FreeLing - Open Source Language Analyzers
//
//    Copyright (C) 2004   TALP Research Center
//                         Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public
//    License as published by the Free Software Foundation; either
//    version 2.1 of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    General Public License for more details.
//
//    You should have received a copy of the GNU General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: Lluis Padro (padro@lsi.upc.es)
//             TALP Research Center
//             despatx C6.212 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
////////////////////////////////////////////////////////////////

#ifndef _TOKENIZER
#define _TOKENIZER

#include <set>
#include <map>
#include <vector>

#include "fries/language.h"
#include "regexp.h"

////////////////////////////////////////////////////////////////
///  Class tokenizer implements a token splitter, which
///  converts a string into a sequence of word objects, 
///  according to  a set of tokenization rules read from 
///  aconfiguration file.
////////////////////////////////////////////////////////////////

class tokenizer {
   private:
	/// abreviations set (Dr. Mrs. etc. period is not separated)
        std::set<std::string> abrevs;
	/// tokenization rules
        std::vector<std::pair<std::string,RegEx> > rules;
	/// substrings to convert into tokens in each rule
        std::map<std::string,int> matches;

   public:
       /// Constructor
       tokenizer(const std::string &);

       /// tokenize string with default options
       std::list<word> tokenize(const std::string &);
       /// tokenize string with default options, tracking offset
       std::list<word> tokenize(const std::string &, unsigned long &);
};

#endif









