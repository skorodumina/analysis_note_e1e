void th_vs_seg(){
gStyle->SetPalette(1);
gStyle ->SetOptLogz(1);
gStyle->SetOptStat(0);

gStyle->SetTitleX(0.56);
gStyle->SetTitleY(0.98);
gStyle->SetTitleSize(0.07,"t");

Short_t k,j;
ostringstream qqq;
TH1 *hist;

  Float_t th_vs_seg_cc_arr[2][6][18] = {{{0., 13.0577, 14.8198, 16.9854, 18.8497, 20.7722, 23.1202, 24.7399, 26.3693, 28.2569, 31.6481, 33.7044, 37.5222, 40.1851, 42.4846, 45.5139, 46.3547, 0.},
                             {0., 12.3663, 14.5647, 16.3118, 18.7031, 20.8298, 22.5443, 24.8247, 26.3913, 28.6392, 31.5305, 33.566, 37.5775, 40.1132, 42.5322, 45., 45., 0.},
                             {0., 12.76, 14.6586, 16.6821, 18.6648, 20.5538, 22.5573, 24.962, 26.4137, 28.3029, 31.6033, 33.7665, 37.4934, 40.0381, 42.3285, 44.8663, 45.,0.},
                             {0., 13.0839, 14.7751, 16.7626, 18.6895, 20.9305, 23.1239, 24.7276, 26.5469, 28.1259, 31.2627, 33.6781, 37.3355, 39.6646, 42.5703, 45., 45., 0.},
                             {0., 12.6631, 16.052, 17.1266, 18.7471, 20.7836, 23.0648, 25.0117, 27.5244, 29.9016, 32.6042, 34.7115, 36.9986, 39.1818, 42.0926, 45., 45., 0.},
                             {0., 12.7948, 14.7214, 16.7988, 18.5596, 20.5496, 22.8541, 24.4748, 26.3951, 28.4766, 31.5388, 33.7486, 37.3584, 40.1278, 42.5831, 45., 45., 0.}},
			     
			     
			    {{0., 9.86866, 10.2744, 11.6061, 13.2822, 15.2113, 16.8047, 19.1317, 21.1941, 22.8422, 23.7821, 26.5811, 27.7998, 31.2606, 34.2189, 36.2558, 39.5832, 0.},
                             {0., 11., 11., 11.6132, 12.6424, 14.3677, 16.8573, 18.49, 20.9482, 22.5705, 23.7656, 26.4239, 27.6032, 30.7262, 33.8834, 36.3639, 38.9472, 0.},
		             {0., 11., 11., 11.643, 13.0375, 14.9574, 16.9836, 18.6356, 21.1218, 22.8459, 23.7062, 26.2906, 27.8548, 31.3241, 34.3427, 36.7193, 39.2374, 0.},
	                     {0., 11., 11., 11.7798, 13.2277, 14.8726, 16.6899, 19.1786, 21.0299, 22.9571, 23.9678, 26.1826, 27.4338, 31.2199, 33.6087, 36.1697, 39.178, 0.},
		             {0., 11., 11., 12.0142, 13.4243, 15.159, 16.8523, 19.0246, 20.7604, 22.5512, 24.7555, 26.934, 29.5094, 30.8662, 35.0397, 36.5057, 39.7693, 0.},
			     {0., 11., 11., 11.628, 13.1929, 15.0126, 16.3127, 19.0631, 20.872, 22.7261, 23.8125, 26.4752, 27.82, 30.8766, 34.2017, 36.4635, 40.1278, 0.}}};		
			     
			     
TCanvas *c = new TCanvas("c","c",0,0,2*250,2*167);
c->Divide();


//TFile *MyFile1 = new TFile("out_25jan17_th_vs_seg_hists_aft_ph_cc_match.root","READ");

//TFile *MyFile1 = new TFile("out_test_aft_th_vs_seg.root","READ");
TFile *MyFile1 = new TFile("out_data_13Nov19.root","READ");
//TFile *MyFile1 = new TFile("out_data_sim_aft_cut.root","READ");

MyFile1->cd();

TLine *line_p[18];
TLine *line_m[18];
TLine *line_c[18];

Float_t avrg;


k=0;
//for (k=0; k<6; k++){
c->cd(k+1);
c->cd(k+1)->SetBottomMargin(0.19);
c->cd(k+1)->SetLeftMargin(0.2);

qqq.str("");
qqq << "th_cc_vs_seg_"<<k+1;
gDirectory->GetObject(qqq.str().c_str(),hist); 


hist->GetXaxis()->SetNdivisions(15);
hist->GetYaxis()->SetNdivisions(8);
hist->GetXaxis()->SetLabelSize(0.06);
hist->GetYaxis()->SetLabelSize(0.06);
hist->GetXaxis()->SetTitle("segment #");
hist->GetYaxis()->SetTitle("#theta_{cc} - #theta_{cc}^{mean} (deg)");
hist->GetXaxis()->SetTitleSize(0.06);
hist->GetYaxis()->SetTitleSize(0.06);

qqq.str(" ");
qqq<< "Sector "<<k+1 ;
hist->SetTitle(qqq.str().c_str());

hist->GetXaxis()->SetRangeUser(2,17);
//hist->GetYaxis()->SetRangeUser(10,47);

hist->Draw("colz");

for (j=1; j<17; j++){

avrg = 0.5*(th_vs_seg_cc_arr[0][k][j] - th_vs_seg_cc_arr[1][k][j]) +th_vs_seg_cc_arr[1][k][j];


cout << th_vs_seg_cc_arr[0][k][j]<<"\n";
line_p[j]= new  TLine(0.5+j,th_vs_seg_cc_arr[0][k][j] - avrg,0.5+j+1,th_vs_seg_cc_arr[0][k][j] - avrg);
line_p[j]->SetLineColor(kBlack);
line_p[j]->SetLineWidth(3);
line_p[j]->Draw("same");

line_m[j]= new  TLine(0.5+j,th_vs_seg_cc_arr[1][k][j] - avrg,0.5+j+1,th_vs_seg_cc_arr[1][k][j] - avrg);
line_m[j]->SetLineColor(kBlack);
line_m[j]->SetLineWidth(3);
line_m[j]->Draw("same");


line_c[j]= new  TLine(0.5+j,0.,0.5+j+1,0.);
line_c[j]->SetLineColor(kBlack);
line_c[j]->SetLineWidth(3);
//line_c[j]->Draw("same");




};



//};
}
