void norm_nphe(){
//gStyle ->SetOptLogz(1);
gStyle->SetOptStat(0);
gStyle->SetTitleSize(0.1,"t");
gStyle->SetStatY(0.9);                
gStyle->SetStatX(0.9);                
gStyle->SetStatW(0.16);                
gStyle->SetStatH(0.11);
gStyle->SetStatFontSize(0.12);
gStyle->SetTitleX(0.6);
TCanvas *c = new TCanvas ("c","c",0,0,500,500);
TCanvas *c1 = new TCanvas ("c1","c1",0,0,500,500);
c->Divide(2,3);//0.048,0.
c1->Divide(2,3);//0.048,0.
Short_t i, j;
ostringstream qqq;
TH2 *hist_tot[6],*hist_fin[6];


TFile *MyFile1 = new TFile("out_13jan17_nphe_2dim_hists.root","READ");
MyFile1->cd();
for (i=0; i<6; i++) {
c->cd(i+1);
c->cd(i+1)->SetBottomMargin(0.2);
c->cd(i+1)->SetTopMargin(0.15);
c->cd(i+1)->SetLeftMargin(0.2);
c1->cd(i+1)->SetBottomMargin(0.2);
c1->cd(i+1)->SetTopMargin(0.15);
c1->cd(i+1)->SetLeftMargin(0.2);

//qqq.str("");
//qqq << "avrg_nphe_sector" << i+1;
//cout << qqq.str().c_str() << "\n";
//gDirectory->GetObject(qqq.str().c_str(),hist);

qqq.str("");
qqq << "h_cc_nphe_total_s" << i+1;
gDirectory->GetObject(qqq.str().c_str(),hist_tot[i]);



/*hist_tot[i]->GetYaxis()->SetLabelSize(0.1);
hist_tot[i]->GetYaxis()->SetNdivisions(5);
hist_tot[i]->GetXaxis()->SetLabelSize(0.1);
hist_tot[i]->GetYaxis()->SetTitle("#varphi_{cc}, deg");
hist_tot[i]->GetXaxis()->SetTitle("#theta_{cc}, deg");
hist_tot[i]->GetXaxis()->SetTitleSize(0.09);
hist_tot[i]->GetYaxis()->SetTitleSize(0.08);*/


//hist_tot[i]->Draw("colz");

qqq.str("");
qqq << "h_cc_nphe_final_s" << i+1;
gDirectory->GetObject(qqq.str().c_str(),hist_fin[i]);


hist_fin[i]->Divide(hist_tot[i]);

qqq.str("");
qqq << "Sector " << i+1;
hist_fin[i]->SetTitle(qqq.str().c_str());
hist_fin[i]->GetYaxis()->SetLabelSize(0.09);
hist_fin[i]->GetYaxis()->SetNdivisions(5);
hist_fin[i]->GetXaxis()->SetLabelSize(0.09);
hist_fin[i]->GetXaxis()->SetNdivisions(5);
hist_fin[i]->GetYaxis()->SetTitle("#varphi_{cc} (deg)");
hist_fin[i]->GetXaxis()->SetTitle("#theta_{cc} (deg)");
hist_fin[i]->GetXaxis()->SetTitleSize(0.09);
hist_fin[i]->GetYaxis()->SetTitleSize(0.08);
hist_fin[i]->GetXaxis()->SetRangeUser(10.,45.);

Int_t colors[] = {1}; 


//hist_fin[i]->SetMaximum(0.8);
hist_fin[i]->SetMinimum(0.8);
//gStyle->SetPalette((sizeof(colors)/sizeof(Int_t)), colors);
hist_fin[i]->Draw("col");
};

//TFile *MyFile2 = new TFile("norm_nphe_15jan17_gt_50.root","recreate");
//MyFile2->cd();
//for (i=0; i<6; i++) {
//hist_fin[i]->Write("", TObject::kOverwrite);

//};
//MyFile2->Write();
 


};
