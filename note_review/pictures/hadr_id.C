double beta_pip(double *x, double *par) {
   double s,mpip;

   mpip=0.13957;

    s = x[0]/sqrt(mpip*mpip+x[0]*x[0]);
       return s;
};



double beta_mu(double *x, double *par) {
   double s,mmu;

   mmu=0.105658;

    s = x[0]/sqrt(mmu*mmu+x[0]*x[0]);
       return s;
};


double beta_k(double *x, double *par) {
   double s,mk;

   mk=0.493667;

    s = x[0]/sqrt(mk*mk+x[0]*x[0]);
       return s;
};



double beta_p(double *x, double *par) {
   double s,mp;
  mp=0.938272;
 //  mp=1.875612793;
    s = x[0]/sqrt(mp*mp+x[0]*x[0]);
       return s;
};

double beta_d(double *x, double *par) {
   double s,md;
 md=1.875612793;
    s = x[0]/sqrt(md*md+x[0]*x[0]);
       return s;
};








void hadr_id(){
gStyle->SetOptStat(0);

gStyle->SetTitleSize(0.08,"t"); 
gStyle->SetTitleX(0.55);

gStyle ->SetOptLogz(1);
gStyle ->SetPalette(1);

TCanvas *c= new TCanvas ("c","c",0,0,350,2*167);
c->Divide(1,2);

TH2 *ph, *ph2;

Short_t j,k,i,t;

TFile *MyFile2 = new TFile("out_data_22jan17_beta_vs_p_hists_cor_noeloss_newbeta_pr_id.root","READ");
TFile *MyFile3 = new TFile("out_data_22jan17_beta_vs_p_hists_cor_noeloss_newbeta.root","READ");


TH2D *h1 = new TH2D("h1","h1",400, 0.,2.0,300, 0., 1.5);
TH2D *h2 = new TH2D("h2","h2",400, 0.,2.0,300, 0., 1.5);
ostringstream qqq;

for (j=1; j<7; j++){
for (i=1; i<=48; i++){
MyFile2->cd();
qqq << "s"<<j<<"_beta_vs_pip/beta_vs_p_pip_" << j<< "_" << i;
gDirectory->GetObject(qqq.str().c_str(),ph);
cout << qqq.str().c_str()<<"\n";
qqq.str("");

if ((j==1)&&(i!=48)) h1->Add(ph);
if ((j==2)&&(i!=16)&&(i!=48)) h1->Add(ph);
if ((j==3)&&(i!=44)&&(i!=48)) h1->Add(ph);
if ((j==4)&&(i!=48)) h1->Add(ph);
if ((j==5)&&(i!=17)&&(i!=48)) h1->Add(ph);
if ((j==6)&&(i!=48)) h1->Add(ph);
};
};

for (j=1; j<7; j++){
for (i=1; i<=48; i++){
MyFile3->cd();
qqq << "s"<<j<<"_beta_vs_p/beta_vs_p_p_" << j<< "_" << i;
gDirectory->GetObject(qqq.str().c_str(),ph2);
cout << qqq.str().c_str()<<"\n";
qqq.str("");

if ((j==1)&&(i!=48)) h2->Add(ph2);
if ((j==2)&&(i!=16)&&(i!=48)) h2->Add(ph2);
if ((j==3)&&(i!=44)&&(i!=48)) h2->Add(ph2);
if ((j==4)&&(i!=48)) h2->Add(ph2);
if ((j==5)&&(i!=17)&&(i!=48)) h2->Add(ph2);
if ((j==6)&&(i!=48)) h2->Add(ph2);
};
};



c->cd(1);
c->cd(1)->SetBottomMargin(0.15);
c->cd(1)->SetLeftMargin(0.15);

h1->GetXaxis()->SetRangeUser(0.05,1.8);
h1->GetYaxis()->SetRangeUser(0.15,1.1);

h1->SetTitle(" ");
h1->GetXaxis()->SetLabelSize(0.05);
h1->GetXaxis()->SetNdivisions(9+200);
h1->GetYaxis()->SetLabelSize(0.05);
h1->GetYaxis()->SetNdivisions(7+200);
h1->GetYaxis()->SetTitle("#beta (dimensionless)");
h1->GetXaxis()->SetTitle("P (GeV)");
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetTitleSize(0.06);

h1->Draw("colz");

TF1 *f3 = new TF1("f3",beta_pip,0.,2.,1);
 f3->SetLineColor(kBlack);
  f3->SetLineWidth(2);
//   f3->SetLineStyle(5);
  f3->Draw("same");


TF1 *f1 = new TF1("f1",beta_mu,0.,2.,1);
 f1->SetLineColor(kBlack);
  f1->SetLineWidth(2); 
  f1->SetLineStyle(5);
  f1->Draw("same");



TF1 *f0 = new TF1("f0",beta_k,0.,2.,1);
 f0->SetLineColor(kBlack);
  f0->SetLineWidth(1); 
  f0->SetLineStyle(3);
  f0->Draw("same");



c->cd(2);
c->cd(2)->SetBottomMargin(0.15);
c->cd(2)->SetLeftMargin(0.15);


h2->GetXaxis()->SetRangeUser(0.05,1.8);
h2->GetYaxis()->SetRangeUser(0.15,1.1);
h2->SetTitle(" ");
h2->GetXaxis()->SetLabelSize(0.05);
h2->GetXaxis()->SetNdivisions(9+200);
h2->GetYaxis()->SetLabelSize(0.05);
h2->GetYaxis()->SetNdivisions(7+200);
h2->GetYaxis()->SetTitle("#beta (dimensionless)");
h2->GetXaxis()->SetTitle("P (GeV)");
h2->GetXaxis()->SetTitleSize(0.06);
h2->GetYaxis()->SetTitleSize(0.06);



h2->Draw("colz");

TF1 *f4 = new TF1("f4",beta_p,0.,2.,1);
 f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
//  f4->SetLineStyle(5);
  
  f4->Draw("same");


TF1 *f2 = new TF1("f1",beta_d,0.,2.,1);
 f2->SetLineColor(kBlack);
  f2->SetLineWidth(2); 
  f2->SetLineStyle(5);
  f2->Draw("same");

TF1 *f00 = new TF1("f0",beta_k,0.,2.,1);
 f00->SetLineColor(kBlack);
  f00->SetLineWidth(1); 
  f00->SetLineStyle(3);
  f00->Draw("same");






};


