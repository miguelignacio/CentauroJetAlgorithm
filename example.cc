//----------------------------------------------------------------------
// Example on how to use this contribution
//
// run it with
//  ./example < single-ep-event.dat
//----------------------------------------------------------------------
//
//----------------------------------------------------------------------
// This file is part of FastJet contrib.
//
// It is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2 of the License, or (at
// your option) any later version.
//
// It is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
// License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this code. If not, see <http://www.gnu.org/licenses/>.
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

#include "fastjet/JetDefinition.hh"
#include "fastjet/PseudoJet.hh"
#include "fastjet/Selector.hh"
#include "CentauroPlugin.hh"
#include "fastjet/EECambridgePlugin.hh"


using namespace std;
using namespace fastjet;

void read_event(vector<PseudoJet> &full_event);

//----------------------------------------------------------------------
int main(){
  // example for the creation and execution of the fastjet plugin
  // for the Centauro jet algorithm
  // 
  // read in input particles
  //----------------------------------------------------------
  vector<PseudoJet> full_event;
  read_event(full_event);

  // create the jet definition using the plugin mechanism 
  //----------------------------------------------------------
  fastjet::contrib::CentauroPlugin * centauro_plugin = new fastjet::contrib::CentauroPlugin(1.0); 
  //The Centauro jet algorithm is described in arXiv:2006.10751, "Asymmetric jet clustering in deep-inelastic scattering", Miguel Arratia, Yiannis Makris, Duff Neill, Felix Ringer, Nobuo Sato.
  
  fastjet::JetDefinition jet_def(centauro_plugin);
  // do the clustering and get the jets
  // only exclusive clustering is supported
  //-----------------------------------------------------------
  ClusterSequence clust_seq(full_event, jet_def);

  vector<PseudoJet> jets = clust_seq.inclusive_jets(0);

  cout << "jets in inclusive clustering " << endl;
  for (unsigned int i=0; i<jets.size(); i++){
    const PseudoJet &jet = jets[i];
    cout << "pt = " << jet.pt()
	 << ", rap = " << jet.rap() << " e " << jet.e() << endl;

  }
  cout << endl;

  jets = clust_seq.exclusive_jets(4);
  
  // print the result
  //----------------------------------------------------------
  cout << "hard jets in exclusive N=4 clustering " << endl;
  for (unsigned int i=0; i<jets.size(); i++){
    const PseudoJet &jet = jets[i];
    cout << "pt = " << jet.pt()
	 << ", rap = " << jet.rap() << endl;

  }
  cout << endl;

  jets = clust_seq.exclusive_jets(500.);

  // print the result
  //----------------------------------------------------------
  cout << "hard jets in exclusive clustering up to d = 500" << endl;
  for (unsigned int i=0; i<jets.size(); i++){
    const PseudoJet &jet = jets[i];
    cout << "pt = " << jet.pt()
	 << ", rap = " << jet.rap() << endl;

  }
  cout << endl;

  return 0;
}

//------------------------------------------------------------------------
// read the event
void read_event(vector<PseudoJet> &full_event){
  string line;

  std::cout << "Particles that are input" << std::endl;
  while (getline(cin, line)) {
    istringstream linestream(line);
    // take substrings to avoid problems when there are extra "pollution"
    // characters (e.g. line-feed).
  
    double px,py,pz,E;
    linestream >> px >> py >> pz >> E;
    PseudoJet particle(px,py,pz,E);
    std::cout << px << " " << py << " " << pz << " " << E <<std::endl;
    // push event onto back of full_event vector
    full_event.push_back(particle);
  }

}
