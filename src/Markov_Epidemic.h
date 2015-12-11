/*
  This file is part of the FRED system.

  Copyright (c) 2010-2015, University of Pittsburgh, John Grefenstette,
  Shawn Brown, Roni Rosenfield, Alona Fyshe, David Galloway, Nathan
  Stone, Jay DePasse, Anuroop Sriram, and Donald Burke.

  Licensed under the BSD 3-Clause license.  See the file "LICENSE" for
  more information.
*/

#ifndef _FRED_MARKOV_EPIDEMIC_H
#define _FRED_MARKOV_EPIDEMIC_H

#include <vector>
using namespace std;

#include "Epidemic.h"
class Disease;

typedef std::vector<Person*> person_vector_t;


class Markov_Epidemic : public Epidemic {

public:
  Markov_Epidemic(Disease * disease);

  ~Markov_Epidemic() {}

  void setup();

  void update(int day);

  void report_disease_specific_stats(int day);

  void end_of_run();

  void process_transition(int day, int i, int j, Person * person);

private:
  int number_of_states;
  person_vector_t * people_in_state;

};

#endif // _FRED_MARKOV_EPIDEMIC_H
