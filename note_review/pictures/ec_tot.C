void ec_tot() {
gStyle ->SetPalette(1);
//gStyle ->SetOptLogz(1);
gStyle->SetOptStat(0);
gStyle ->SetStatFontSize(0.08);
gStyle->SetTitleSize(0.07,"t"); 
gStyle->SetTitleX(0.55);


TCanvas *c2 = new TCanvas("c2","c2",0,0,700,230);
c2 -> Divide(2,1);

TH2F *h_ectot1, *h_ectot2;

TFile *MyFile = new TFile("out_test_12Nov19_2.root","READ");

MyFile->cd();
gDirectory->GetObject("ectot_sector1",h_ectot1);


TFile *MyFile2 = new TFile("out_test_12Nov19_3.root","READ");

MyFile2->cd();
gDirectory->GetObject("ectot_sector1",h_ectot2);


c2->cd(1);
c2->cd(1)->SetBottomMargin(0.2);
c2->cd(1)->SetLeftMargin(0.2);

h_ectot1->GetXaxis()->SetLabelSize(0.08);
h_ectot1->GetYaxis()->SetLabelSize(0.07);
h_ectot1->GetXaxis()->SetTitle("P_{e'} (GeV)");
h_ectot1->GetYaxis()->SetTitle("E_{tot}/P_{e'} (dimensionless)");
h_ectot1->GetXaxis()->SetTitleSize(0.08);
h_ectot1->GetYaxis()->SetTitleSize(0.08);
h_ectot1->GetYaxis()->SetTitleOffset(0.8);

h_ectot1->SetTitle("With 1st CC segment");
h_ectot1->Draw("colz");


c2->cd(2);
c2->cd(2)->SetBottomMargin(0.2);
c2->cd(2)->SetLeftMargin(0.2);


h_ectot2->Draw("colz");
h_ectot2->GetXaxis()->SetLabelSize(0.08);
h_ectot2->GetYaxis()->SetLabelSize(0.07);
h_ectot2->GetXaxis()->SetTitle("P_{e'} (GeV)");
h_ectot2->GetYaxis()->SetTitle("E_{tot}/P_{e'} (dimensionless)");
h_ectot2->GetXaxis()->SetTitleSize(0.08);
h_ectot2->GetYaxis()->SetTitleSize(0.08);
h_ectot2->GetYaxis()->SetTitleOffset(0.8);

h_ectot2->SetTitle("Without 1st CC segment");

}
