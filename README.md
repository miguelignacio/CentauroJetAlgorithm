08/04/20. This code is now superseded since Centauro is now part of Fastjet Contrib since release fj contrib-1.045 https://fastjet.hepforge.org/contrib/


# CentauroJetAlgorithm
Implementation of the Centauro jet algorithm (described in ["Asymmetric jet clustering in deep-inelastic scattering"](https://arxiv.org/abs/2006.10751) by Miguel Arratia, Yiannis Makris, Duff Neill, Felix Ringer, Nobuo Sato, [arXiv:2006.10751](https://arxiv.org/abs/2006.10751)) using the FastJet contrib classes. 

The Centauro jet algorithm is intended to be used in deep-inelastic scattering (DIS) and is suited for the family of frames connected to the Breit frame by longitudinal boosts. 
Its distance measure accounts for the forward-backward asymmetry in the Breit frame. It is longitudinally invariant and can cluster jets with Born kinematics, which enables novel studies of TMD observables.

We plan to include this code in the standard fastjet-contrib release. Meanwhile we release it here for the jet aficionados that would like to try it. 
To install it, you should copy this folder as "CentauroPlugin" in your fastjet contrib folder (https://fastjet.hepforge.org/contrib/) along with all the other plugings. 

Then do
  `./configure --only=CentauroPlugin --fastjet-config=YOURPATH/fastjet-install/bin/fastjet-config CXXFLAGS=-fPIC CFLAGS=-fPIC`
  
Then do
  `make`
  `make install`
  
You can then run an example doing:
  `cd CentauroPlugin`
  `make example`
  `./example < ../data/single-epDIS-event.dat`

where single-epDIS-event.dat contains the 4-momentum of the final-state particles of 1 DIS event generated with Pythia8. 

Note that you should include `#include "fastjet/contrib/CentauroPlugin.hh"` in your example. 
Your Makefile should include`-L$(FASTJET3_LIB) -Wl,-rpath,$(FASTJET3_LIB) -lfastjet -lCentauroPlugin\`

If that does not work, try this way (suggested by Jinlong Zhang and Liang Zheng)

`Use the Makefile inside the fjcontrib directory, do “make libfastjetcontribfragile.so” and then include this .so file in my Makefile by “-L/path_to_there/ -lfastjetcontribfragile”. Of course, the “path_to_there” should be included in the LD_LIBRARY_PATH while running the code later.`

The Centauro algorithm is an asymmetric hybrid between longitudinally-invariant algorithms used in pp collisions and spherically-invariant algorithms used in e+e- collisions. 

![alt text](https://github.com/miguelignacio/CentauroJetAlgorithm/blob/master/Centauro.png?raw=true)
