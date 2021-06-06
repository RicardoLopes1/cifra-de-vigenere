#include <bits/stdc++.h>
using namespace std;
// ferramentas para auxiliar
// https://www.cs.du.edu/~snarayan/crypt/vigenere.html
// https://crypto.interactive-maths.com/kasiski-analysis-breaking-the-code.html

string encMsg = "p uoucxfetsztp rbgzob jotzp b gradldzdslp irccmler. cgupdr cgu z rle km abieum dfi ue xcpwekazs ue mul veinmctzdslp, rle wvdjeani npd maltbj daoturik m ofjefdzmmis iaqj. edm dbsis yff fs viopj dga ftlajqzt eag mdurvsu pwrpgzlouo, iclouo wtp svsgtgfl mwzrvchsz xbzs xcyef sgjcf f akafoko, hmcdvbwc bvv ok uptdo viopj ekblwrm kmyef mavlefs hwc vda avovjtjql, tvnvw l ofski towojuldro mul gfrei of dejklefrai, dfedg wd dllhiopj, nga xfjmg, xzs eag tpsdok wd uvrewd f tofkzsuajuzt dekuz tvm dmc. ufdsa lt eokalt znxwcnrcgmd fjtsw dfedg icnrzwvlers, avefiauwpt, toexcbj ng klskag, tzdrlahldro w med, jeflz dflwblers wu efdpg zpbc, e kmyef laolers s vztja alpokiviof, wojvpdvnvw fn wlmfz ev cgqdbj rwtldzofiobj ag vztjo avefiekap ev auwcef cgu lt znxwcnrcgmd pstallt. tofbl urmtmx dfmg nzsrm malefs ga obuok vlt vlwqnpvs, mbtmzzsvop fs viopj otbtefs hicb grgkfsrr hmdtfak yff duvix ev ohqyjro eitt wauqwnvnlm. npd o scxfetg ll uvcfwwpxis, id qvskwlt gakalsrm s aps dafqavcavid, qfricp dfm ga obuok ofbidslzt, rs avqpimskzfj ssw upxavid ev auwcef cgu lt eokalt grwnpsvnuqlt. kenm fnr csuabehs mx vd dwbpsdifiop gaaa of gekazbj nwocbj e avojrnsa, yjjsg mwfj rwazmmejix bgoaic pj ifltbeok. cxb vmhzptr fwh fnr csuabehs xlsr ifkpokinic qvskwlt eeyzlt v jgdpoj a fiz wftsz, npdo mu xpmiemyuf dw xcpkekbz dfm g ozwvrfw, ltjie wd kfvwvd oro nwebiae, zptllliyef akatn ea nqepiis lzt znvqlofs. wadb vmhzptr, a uixciivop beadgejta malwr ak qygfreinpvs hicb dafqavcaj wd erdga, ybf iexzskaflz tv ejix wvraltdfs gc qbbefmht.";
// key = ?
string encrypt(string msg, string key);
string decrypt(string msg, string key);
/*
a1 b2 c3 d4 e5 f6 g7 h8 i9 j10 k11 l12 m13 
n14 o15 p16 q17 r18 s19 t20 u21 v22 w23 x24 y25 z26 
*/
int main(){
    string msg = "o conhecimento salva vidas";
    string key = "parabens"; // chave com 8 letras, palavra em português.
    
    string enc = encrypt(msg, key);
    
    cout << "Message: " << msg << endl;
    cout << "Key: " << key << endl;
    cout << "Encrypted message: " << enc << endl;
    
    cout << "------------\n";
    
    cout << "Encrypted message: " << enc << endl;
    cout << "Key: " << key << endl;
    cout << "Decrypted message: " << decrypt(enc, key) << endl;
    
    /***** salvar em um arquivo *****
    ofstream out("arquivo.txt");
	out << decrypt(encMsg, key);
	out.close(); 
    */ 
    
    return 0;
}

string encrypt(string msg, string key){
    int loop, j, keySize;
    string s = "";
    j = 0;
    keySize = key.size(); 

    for(int i = 0; i < msg.size(); i++){
        if(msg[i] == ' ' or msg[i] == '.' or msg[i] == ','){
            s += msg[i];
        }// . , space 
        else{
            if( msg[i] + (key[j] - 'a') > 'z'){
                loop = msg[i] + (key[j] - 'a') - 'z' - 1;
                s += 'a' + loop;
            }else{
                s += msg[i] + (key[j] - 'a');
            }
            j = (j+1)%keySize;
        }// else
    }// for
    return s;
}

string decrypt(string msg, string key){
    int loop, j, keySize;
    string s = "";
    j = 0;
    keySize = key.size(); 

    for(int i = 0; i < msg.size(); i++){
        if(msg[i] == ' ' or msg[i] == '.' or msg[i] == ','){
            s += msg[i];
        }// . , space 
        else{
            if( msg[i] - (key[j] - 'a') < 'a'){
                loop = msg[i] - (key[j] - 'a') - 'a' + 1;
                s += 'z' + loop;
            }else{
                s += msg[i] - (key[j] - 'a');
            }
            j = (j+1)%keySize;
        }// else
    }// for
    return s;
}
