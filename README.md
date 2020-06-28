# CentauroJetAlgorithm
Implementation of the Centauro jet algorithm ("Asymmetric jet clustering in deep-inelastic scattering" Miguel Arratia, Yiannis Makris, Duff Neill, Felix Ringer, Nobuo Sato, arXiv:2006.10751) using the FastJet contrib classes. 

The Centauro jet algorithm is intended to be used in deep-inelastic scattering (DIS) and is suited for the family of frames connected to the Breit frame by longitudinal boosts. 
Its distance measure accounts for the forward-backward asymmetry in the Breit frame. It is longitudinally invariant and can cluster jets with Born kinematics, which enables novel studies of TMD observables.

We plan to include this code in the standard fastjet-contrib release. Meanwhile we release it here for the jet aficionados that would like to try it. 
To install it, you should copy this folder as "CentauroPlugin" in your fastjet contrib folder (https://fastjet.hepforge.org/contrib/) along with all the other plugings. 

Then do
  `./configure --only=CentauroPlugin --fastjet-config=YOURPATH/fastjet-install/bin/fastjet-config CXXFLAGS=-fPIC CFLAGS=-fPIC`
  
Then do
  `make`
  `make install`
  
You can then run an example with 
  `./example < ../data/single-epDIS-event.dat'

where single-epDIS-event.dat contains the 4-momentum of the final-state particles of 1 DIS event generated with Pythia8. 
