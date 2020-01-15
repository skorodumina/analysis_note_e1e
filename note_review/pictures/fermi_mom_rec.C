void fermi_mom_rec(){
gStyle->SetOptStat(0);
gStyle->SetOptFit(0011);

gStyle->SetStatY(0.9);                
gStyle->SetStatX(0.99);                
gStyle->SetStatH(0.08);
gStyle->SetStatW(0.21);                

//gStyle->SetStatFontSize(0.1);

gStyle->SetTitleSize(0.15,"t");
gStyle->SetTitleX(0.55);
gStyle->SetTitleY(1.025);
TCanvas *c= new TCanvas ("c","c",0,0,1350,300);
c->Divide(5,1);

TH1F *hmomres[5];

Short_t i;

TFile *MyFile2 = new TFile("out_test_17Nov19_momrec_2.root","READ");

 TF1 *g1 =  new TF1("m1","gaus",-0.015,0.015);
ostringstream qqq;
for (i=0; i<5; i++){




qqq << "excl_top_plots/h_0_mis_all_reg_sim_" << i;
gDirectory->GetObject(qqq.str().c_str(),hmomres[i]);
cout << qqq.str().c_str()<<"\n";
qqq.str("");

c->cd(i+1);
c->cd(i+1)->SetBottomMargin(0.18);
c->cd(i+1)->SetLeftMargin(0.2);

hmomres[i]->Draw("hist");



hmomres[i]->GetXaxis()->SetLabelSize(0.06);
hmomres[i]->GetXaxis()->SetNdivisions(5);
hmomres[i]->GetYaxis()->SetLabelSize(0.06);
hmomres[i]->GetYaxis()->SetNdivisions(4);
hmomres[i]->GetXaxis()->SetTitle("P_{gen} - P_{X} (GeV)");
//hmomres[i]->GetYaxis()->SetTitle("counts");
hmomres[i]->GetXaxis()->SetTitleSize(0.06);
hmomres[i]->GetYaxis()->SetTitleSize(0.09);
hmomres[i]->GetXaxis()->SetTitleOffset(1.2);
hmomres[i]->GetYaxis()->SetTitleOffset(0.75);
hmomres[i]->Scale(1./hmomres[i]->GetMaximum());

hmomres[i]->SetAxisRange(-0.075,0.075,"X");
hmomres[i]->SetAxisRange(0.,1.25,"Y");

qqq<<1.3+0.1*i << " GeV" << " < W < " << 1.3 + 0.1*(i+1)<< " GeV" ;
hmomres[i]->SetTitle(qqq.str().c_str());
qqq.str(" ");

hmomres[i]->Fit(g1,"R+");
g1->Draw("same");
};




};
