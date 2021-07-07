// To compile 
// root -l
// gSystem->Load("libLatinoAnalysisMultiDraw.so")
// .L hww_VBF_MYmvaBDTG.C+ 

#include "TMVA/Reader.h"
#include "TLorentzVector.h"
#include "TTree.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TString.h"
#include "TFile.h"
#include "TChain.h"

using namespace std;

namespace multidraw {
  extern thread_local TTree* currentTree;
}

TMVA::Reader* myreaderBDTG4D3= new TMVA::Reader();

bool initialized = false;

TString name_temp = "";


// Variables fed into the BDT

float loc_mll;
float loc_PuppiMET_pt; 
float loc_CleanJet_pt_0;
float loc_CleanJet_pt_1;
float loc_CleanJet_eta_0;
float loc_Jet_btagDeepB_CleanJet_jetIdx_0;
float loc_CleanJet_eta_1;
float loc_mT2;
float loc_mjj;
float loc_pt1;
float loc_pt2;
float loc_mth;
float loc_dphilmet;
float loc_dphilmet1;
float loc_mtw1;
float loc_mtw2;
float loc_dphijet1met;
float loc_dphilljet;
float loc_mindetajl;
float loc_detajj;
float loc_dphijj;
float loc_pTWW;
float loc_njet;

int loc_CleanJet_jetIdx_0;

// Variables from the tree

float loc0_mll;
float loc0_PuppiMET_pt; 
float loc0_CleanJet_pt[100];
float loc0_CleanJet_eta[100];
float loc0_Jet_btagDeepB[100];
float loc0_mT2;
float loc0_mjj;
float loc0_pt1;
float loc0_pt2;
float loc0_mth;
float loc0_dphilmet;
float loc0_dphilmet1;
float loc0_mtw1;
float loc0_mtw2;
float loc0_dphijet1met;
float loc0_dphilljet;
float loc0_mindetajl;
float loc0_detajj;
float loc0_dphijj;
float loc0_pTWW;
float loc0_njet;

int loc0_CleanJet_jetIdx[100];

float bVeto(float* Jet_btagDeepB, int CleanJet_jetIdx)
{
    if (CleanJet_jetIdx >=0)
        return Jet_btagDeepB[CleanJet_jetIdx];
    else
        return -2;
}

void initmyreaderBDTG4D3(TTree* tree)
{
    tree->SetBranchAddress("mll", &loc0_mll);
    tree->SetBranchAddress("PuppiMET_pt", &loc0_PuppiMET_pt);	
    tree->SetBranchAddress("CleanJet_pt", &loc0_CleanJet_pt);	
    tree->SetBranchAddress("CleanJet_eta",&loc0_CleanJet_eta);	
    tree->SetBranchAddress("Jet_btagDeepB", &loc0_Jet_btagDeepB);	
    tree->SetBranchAddress("mT2", &loc0_mT2);	
    tree->SetBranchAddress("mjj", &loc0_mjj);	
    tree->SetBranchAddress("pt1", &loc0_pt1);	
    tree->SetBranchAddress("pt2", &loc0_pt2);	
    tree->SetBranchAddress("mth", &loc0_mth);	
    tree->SetBranchAddress("dphilmet", &loc0_dphilmet);	
    tree->SetBranchAddress("dphilmet1", &loc0_dphilmet1);	
    tree->SetBranchAddress("mtw1", &loc0_mtw1);	
    tree->SetBranchAddress("mtw2",&loc0_mtw2);	
    tree->SetBranchAddress("dphijet1met", &loc0_dphijet1met);	
    tree->SetBranchAddress("dphilljet", &loc0_dphilljet);	
    tree->SetBranchAddress("mindetajl", &loc0_mindetajl);	
    tree->SetBranchAddress("detajj", &loc0_detajj);	
    tree->SetBranchAddress("dphijj", &loc0_dphijj);	
    tree->SetBranchAddress("pTWW", &loc0_pTWW);
    tree->SetBranchAddress("njet", &loc0_njet);
    tree->SetBranchAddress("CleanJet_jetIdx", &loc0_CleanJet_jetIdx);

    // The variables' names and their order have to agree with those defined in TMVAClassification.C file
    myreaderBDTG4D3->AddVariable("mll", &loc_mll);
    myreaderBDTG4D3->AddVariable("PuppiMET_pt", &loc_PuppiMET_pt);	
    myreaderBDTG4D3->AddVariable("Alt$(CleanJet_pt[0],0)", &loc_CleanJet_pt_0);	
    myreaderBDTG4D3->AddVariable("Alt$(CleanJet_pt[1],0)", &loc_CleanJet_pt_1);	
    myreaderBDTG4D3->AddVariable("Alt$(CleanJet_eta[0],0)", &loc_CleanJet_eta_0);	
    myreaderBDTG4D3->AddVariable("Alt$(Jet_btagDeepB[CleanJet_jetIdx[0]],-2)", &loc_Jet_btagDeepB_CleanJet_jetIdx_0);	
    myreaderBDTG4D3->AddVariable("Alt$(CleanJet_eta[1],0)", &loc_CleanJet_eta_1);	
    myreaderBDTG4D3->AddVariable("mT2", &loc_mT2);	
    myreaderBDTG4D3->AddVariable("mjj", &loc_mjj);	
    myreaderBDTG4D3->AddVariable("pt1", &loc_pt1);	
    myreaderBDTG4D3->AddVariable("pt2", &loc_pt2);	
    myreaderBDTG4D3->AddVariable("mth", &loc_mth);	
    myreaderBDTG4D3->AddVariable("dphilmet", &loc_dphilmet);	
    myreaderBDTG4D3->AddVariable("dphilmet1", &loc_dphilmet1);	
    myreaderBDTG4D3->AddVariable("mtw1", &loc_mtw1);	
    myreaderBDTG4D3->AddVariable("mtw2", &loc_mtw2);	
    myreaderBDTG4D3->AddVariable("dphijet1met", &loc_dphijet1met);	
    myreaderBDTG4D3->AddVariable("dphilljet", &loc_dphilljet);	
    myreaderBDTG4D3->AddVariable("mindetajl", &loc_mindetajl);	
    myreaderBDTG4D3->AddVariable("detajj", &loc_detajj);	
    myreaderBDTG4D3->AddVariable("dphijj", &loc_dphijj);	
    myreaderBDTG4D3->AddVariable("pTWW", &loc_pTWW);
    myreaderBDTG4D3->AddVariable("njet", &loc_njet); 
   
    //change the path of weight file, xml file is in " BDT_config/weight " folder .
    myreaderBDTG4D3->BookMVA("BDT","/afs/cern.ch/user/s/ssaumya/Projects/WW_Analysis_Work/WW_Cuts_Optimization/CMSSW_10_6_4/src/PlotsConfigurations/Configurations/WW/FullRunII/Cuts_Optimization_ttbar/Optimizing_top-antitop_bg_v1/weights/TMVAClassification_BDTG4D3.weights.xml"); 

}


float WW_against_top_bg_BDT(int entry, int nclass)
{
    if(name_temp != multidraw::currentTree->GetCurrentFile()->GetName())
	{
		std::cout << "name_temp = " << name_temp << endl;
		name_temp = multidraw::currentTree->GetCurrentFile()->GetName();
		std::cout << "name_temp = " << name_temp << endl;
		initialized = false;
	}

    if (!initialized)
	{
		//latino = (TTree*)gDirectory->Get("latino");
		delete myreaderBDTG4D3;
		myreaderBDTG4D3 = new TMVA::Reader();
		initmyreaderBDTG4D3(multidraw::currentTree);
		cout << "check init" << endl;	
		initialized = true;		
    }

    multidraw::currentTree->GetEntry(entry);

  
    loc_mll = loc0_mll;
    loc_PuppiMET_pt = loc0_PuppiMET_pt;
    loc_CleanJet_pt_0 = loc0_CleanJet_pt[0];
    loc_CleanJet_pt_1 = loc0_CleanJet_pt[1];
    loc_CleanJet_eta_0 = loc0_CleanJet_eta[0];
    loc_Jet_btagDeepB_CleanJet_jetIdx_0 = bVeto(loc0_Jet_btagDeepB, loc0_CleanJet_jetIdx[0]);
    loc_CleanJet_eta_1 = loc0_CleanJet_eta[1];
    loc_mT2 = loc0_mT2;
    loc_mjj = loc0_mjj;
    loc_pt1 = loc0_pt1;
    loc_pt2 = loc0_pt2;
    loc_mth = loc0_mth;
    loc_dphilmet = loc0_dphilmet;
    loc_dphilmet1 = loc0_dphilmet1;
    loc_mtw1 = loc0_mtw1;
    loc_mtw2 = loc0_mtw2;
    loc_dphijet1met = loc0_dphijet1met;
    loc_dphilljet = loc0_dphilljet;
    loc_mindetajl = loc0_mindetajl;
    loc_detajj = loc0_detajj;
    loc_dphijj = loc0_dphijj;
    loc_pTWW = loc0_pTWW;
    loc_njet = loc0_njet;
  
    float classifier = myreaderBDTG4D3->EvaluateMVA("BDT");

    return classifier;

}




 
 


