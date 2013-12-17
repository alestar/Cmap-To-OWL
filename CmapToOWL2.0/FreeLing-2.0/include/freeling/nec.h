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

#ifndef _NEC
#define _NEC

#include <set>

#include "fries.h"
#include "omlet.h"

////////////////////////////////////////////////////////////////
///  The class nec implements a ML-based NE classificator
////////////////////////////////////////////////////////////////

class nec {
   private: 
     /// feature extractor
     fex* extractor;
     /// lexicon to translate symbolic features to integer indexes
     std::map<std::string,int> lexicon;
     /// adaboost classifier
     adaboost* classifier;
     // tag of NPs to classify
     std::string NPtag;

   public:
      /// Constructor
      nec(const std::string &, const std::string &); 

      /// Classify NEs in given sentence
      void analyze(std::list<sentence> &) const;

};

#endif

