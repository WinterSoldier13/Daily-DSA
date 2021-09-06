#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define lli long long int

int difference(string s1, string s2)
{
    if (s2.size() < s1.size())
    {
        return difference(s2, s1);
    }
    if (s1 == s2)
    {
        return 0;
    }
    if (s1.size() == s2.size())
    {
        return 0;
    }

    unordered_map<char, int> hashmap;
    for (auto x : s1)
    {
        hashmap[x]++;
    }
    int diff = 0;
    for (auto x : s2)
    {

        if (diff > 1)
        {
            return 0;
        }
        if (hashmap.find(x) == hashmap.end())
        {
            diff++;
        }
        else if (hashmap.find(x) != hashmap.end())
        {
            hashmap[x]--;
            if (hashmap[x] == 0)
            {
                hashmap.erase(x);
            }
        }
    }
    return diff == 1;
}


int customSort(string s1, string s2)
{
    return (s1.size()<s2.size());
}

int dynamic(vector<string> &arr)
{
    int l = arr.size();
    vector<int> dp(l, 0);

    sort(arr.begin(), arr.end(), customSort);
    for(int i =0;i<arr.size();i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }
    for (auto x : arr)
    {
        cout << x << endl;
    }
    dp[0] = 0;



    for (int i = 1; i < l; i++)
    {
        int max_ = dp[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (abs((int)arr[j].size() - (int)arr[i].size()) > 1)
            {
                break;
            }

            if (difference(arr[j], arr[i]))
            {
                max_ = max(max_, dp[j] + 1);
            }
        }
        dp[i] = max_;
    }
    for (auto x : dp)
        cout << x << " ";
    cout << endl;

    int maxEle = 0;
    for (auto x : dp)
        maxEle = max(maxEle, x);
    return maxEle + 1;
}
int longestStrChain(vector<string> &words)
{
    return dynamic(words);
}

int main()
{
    // vector<string> arr{"a", "b", "ba", "bca", "bda", "bdca"};
    vector<string> arr{"lcnbweqxtninxcin","jfaipbnicamqexhe","tsuttpotsqouyhfr","qbuxsekrcfpurnlg","guirabocqrlpbhcm","vyymdaanhwcclqwc","qhyaecoeelkofood","dxcahxyndyemrxjk","hsncxuhshotmlxxb","vuvroyvhfbevpmvj","cibaplqjjrwquqbi","rqpocwkwtrwbsjyy","zljuiwidlsewrdxo","wzfngzddmtmxoavt","coldplxzjkgxjxyl","gquwdqfkqqlcqajk","kjzodrsieiwbdqys","vkqznswmjqrwfypm","vjfzndbptrihicwt","sqbxkqsubaplvgbq","bwngakyvauqgbvwr","zfdbedlvwutidltc","rqdxvoklmdvqkkcx","mpqefpmlywtauway","cqpfsxxyxdzqluoo","krfwragglwtihtnt","ucrfnqejddycrved","wsurwsajilfxedrz","bfqukeeacxtvwcya","vhljeufvlttkewhq","jkdwnyszuyellazw","ufrtjikuasuebdat","etrzruranawwcogf","chmxqhnncookohnv","jvzzxxievblpajit","aqakdcselnwaoauq","iddymoghuyqzygkz","yzfvpftkjujxkscj","fsmvjxdsndjkijfn","pcihzvrwpoggulbo","lawweuzumiphwrvm","xycscdgqfksfxmeh","scjdrgtnfmlgkrwt","emnttsapqxwxfudw","pivzwqhfblgrfrgt","ecyopwimivgpbjiv","xckeuabyrffksnnk","cmztswafhaeegima","jofpzbgskdgxnznz","owhjbkqhrpkvcoca","mlztgocivjuoohvt","dayustiiekxidgit","lgeqlfntvbqtwrxf","gqdqnduwyhvruull","jvdumsqxpmjspqgj","mbjlneddhoalaibq","axekidpkbvmfyemi","ztamrukzmdxicbni","gawhrloxdfrwlmjs","rtzljaiiragujobg","qsjuuqfaqjaiuwpz","beguxbpzudhkpfom","ckwyivcnklkpsmwe","ycaffhinuclsueru","urjrhigckddtoikx","bhtgjerifihpbbhu","rsmsmupitueyjfkm","jwhpuxqnmlysfwtd","drvupjocufyolrdm","fnnxpucglepcehmy","drrmztnrspjltwrh","nmcpsvwadqowedfi","kpgkpbzmiqzotqso","qdlbdevdapjkusey","whviedqfvhlrmopd","wvzlyehzwliwwfcm","ovbnomiqeeofrppg","trcqryzgzfqqhjmu","adpobuuebrgmrsmd","hobfxaoavnappnma","bwqrrvgvusvolmwc","arxbvmhnnkbxorha","eouwdliitwysiaxh","gncgewkfprvtsbct","fgjefbnjcqnkydji","rgqvmlctryhdlteu","btydtahyinatvokm","qkagmarwspsxrimk","pydezhqpwifkatob","fimromzswsariqyw","mrxwosllnfrbbamr","swnsuuysrmnsoxzj","ztsmovayimnjkiai","gfkvqrvpbbkrvtyo","ibyarxjwhflcpcfu","ikjwqgtborechawg","vjchacseaqoyixeg","idwowkrvlfpfwbcc","anuwwiskyvkalosk","doihabreqeviovas","ydjvnkupzenpwmuw","zwmyjnqsdkwcetrs","tujyejlrdsuhvpan","opqjseueimhniugh","iilfpwgrtadccbsy","xcywigswwjgyumgh","xbigospmntpiivst","gnrfivwenurpbbwz","zcbtyxmvbkhhtglc","pfaqmwrmwvftpzhq","gszfavkekcosinos","ajmwljjxconlxizv","rdhdrbompbprwlry","yjjjaasfrmriijey","nkkezshjkzxznlzl","huajpndmerdkarrk","oqluffuqpglmkfvq","pcktcgorfdzwecxt","jlhvskqziamwhkvv","axqtgodtwwarznge","hewkxlfhizpxmpwl","frlpboshwmtpcyvf","ldmmmkpxddwjooch","hgootncxdadsedln","socabtirmypevcjd","kxfhcaqnglomqqdi","kjkurkhodgxfxnnc","htybmfixfjhzjokx","xnafqhxmeyvwqioj","zmwafdlweewysdig","wssbmjtknlulvoin","aoegwvnynojcjgch","coxndmivgdyjclib","bjbosqjpbevesdpp","tqnrcaetmbrvfzii","ppptuednhiagzhcw","xrdendtbklphctey","nvtupfqomgxydstr","llextaxoqvurbyzk","mssguzklaelsvezg","uyhoodumbfkwkcso","ihgvexucjizgganu","qrpcepneofybgfec","ntlfejxifgcgkwfe","qnxhvvvoqdswcogf","osyqzbdhomyrkxtu","ccjzrffrvawfypqb","pasacwmkuczixhhb","zrwqwdtdpluskitw","eehnitsdgybirspb","pdfcksncqbujbshx","hvwmkekuckwmgzfj","iplrcemfvpesqfcs","ouubjpmtwkxkzyty","kitgabhfaecnoqum","rfrhjtpanzocpevp","ruzlwahzyvbhaisz","nhrxnygymfowbojt","ngnxuhnqyqrtbfka","zgdregweyhmxsdcv","fxtqdusbstxqzczb","yojlbjshwahmflrg","mgonthribhgawehy","lrijoromrovvxqgt","ifyesudvaufxbzdf","mgreilxeeflgrslt","dxfbxvpdtcrhhidi","lednpimbotnzsanv","fdcbndwpwicrjkgt","qongiijchwzhcxtp","hxrtyzihcenalniy","eaqwwvxtfvoqahkx","ukdzzptcmnbjzska","sznuuhsahbgjsrcc","oyvsqljjvxnmfoej","tgdwquqjijwwvhex","jauskibjmqqenrsp","jbekvcbuxmjvzsvn","vdvoqdmubqwtzera","jxprotavcdphqhrh","pvxsfxkzxujasnnh","eifqqxbvcqegypon","enpfzrjvxmghnwsc","ybygkutlylczqsic","idoazdsvqfydekrw","heoxczwcesvrjxbh","zozblhhzlxazbrad","tlnarwbqokrdsast","ffadrdbsilzfsomo","zzcjnecxschprodv","yuzdmsjsbgcjfxvo","rudaitphunkcmovh","oxatmxsefkwkjgle","ywnypvpofmflqpkd","upvxxkgmiygbwgkl","enamictwsqqfzypx","fvqadewocmrcenjy","ojudnmtlfbiitxtb","vhjssljtykwnqyfi","luimwisdvmgckjfy","sajfdklqfqljebqi","axokngshyafdyoar","tozqgscuiaygcuoj","uywzbudhhjvthoit","uusypyydylrtgiqg","xllqtmjbahjlkyhc","cnehapqkahpmzubh","eghzuunzniworsve","jpqvejqkwaujiiha","msaakjffbehibpwj","gagiwdqwwpjqawrp","lxumcyqklpanxugf","dqtkmadsrmajegxx","rkuiavdnpqbflqes","fqygfrefoioqqcdj","xajivxuxtkbansxb","luoettrszudfdmus","lzpchbfkbdqbxqmd","yetrwmtbjvyypahk","jakbbxkkdjokhqnx","kummrtgzkdafuzrn","vislivlmdmsobdxd","xtksjsyottrnpdho","trqflljycjbxgnvg","pujfnearaolfxrej","aldpbdmzjzntngja","icbxdfywpmknohkz","nywygojjhxytdqjz","qajlmfpppjrnwebg","myrgqmxihrqoaouu","dadgxpgvtejcnete","glfwqhctzvxhqvto","wodyfynktlkwhkkr","maikfiunfuilmnon","sqicbctnlcbljgcw","qejudtegtvutrhip","fhudpsmpinzsyjeo","rpjtvogyzunjmwiw","snrjnqjzunbjdnsa","jwtfjabawxqdqzya","ywzueecpdljqipkq","jncmquuzsgmpqxxv","kfydqyyyckfcimlh","jinkwjiszicqbjhj","juknqglujuiprmct","ctlorgpioekcxjik","cbixrbpydqreyqtl","nvjsmqntpqiasejk","xnirgfaavbmyjjua","fkftjqorcxncdurh","canszwixaeimufac","odptzjbxzmykjpig","zuyxfrcrplkgsqig","zsynrdxfejjqtlte","krrwrnbyfdxkbezv","wicuvfxzmgtqoyec","chutijkcgwrszwon","nwimobikkpljklze","mdiinpkfuqontpzn","kcrfpsejlmbqdnoy","nrmgmhzbygoyacgb","ijzydzyrcrofgstx","gklfevnmnuirdxvl","boimgtrlctjszeoh","xdxhzxvzsnuiyyka","hoxdlaitynwhkdyu","nfatfyztpdguscqf","rsrdwgyzjktllmza","mkvdnvdtgapfluqr","zhruierlynytiftc","ezxoqmksnmiixheh","fkrtetykzaparona","riqvveatrddeyamj","delocwddhgswtpdj","moytgsvooenrltft","knsebpnspzhhqbdl","cbmxckxizbbxaecq","wdulhkvpmxgevgqi","dyegdgroxssobwjk","pdrmiaxggxvhstda","uqzkykmveccfrkkq","mrxtkwqzhnyhnibf","kltizehyyuqjmbti","diizvxtpukjenpjx","yadjhozygwchdypx","ebojmzpvehcbtzmk","vpeyhttensotxxpq","qvfljrckqryzekeb","dnhcafmkmdyvlopj","qdxbfvcepzeberyx","xrtlymegjeagcjdg","qgewwpokologsdmd","tgpkxpofqtisuxxo","yrbyreecomkzazue","timsskqwzvduogwe","lpxlpplfhdapvjru","tpxxcprycpuwswzw","vfyvmkucogrvfxsf","jkwdwhbhcbusyjnu","ysyckusurqykwcfc","gionhffggibfuinf","ndskbyejkwbyjzxa","bqkeuyfsgyaryplb","hmxmmpfhgblbrqzh","rzcewdubghckrrkx","ijcpgmznphumldqh","admsrrwlaufvdoar","qokokxbygprautiv","sotbrebuitiloyio","lhlkeoydcrsfnmgx","sjbceqmownqcuois","nojxmgslqcgfqart","vkcvmfslytxzykwm","hinwfhqytzaofmca","egzitmmqliemnhgp","jxiavayzctxvwrtz","duyklokrvreijahl","bixnpvradtkakigo","eahxaavkpypyfwbs","ydmqippopmhtcknn","djwjlcnydwjaammi","dkszlgtyvjaomiaw","guxyfwqzvzdcgokd","cnvfzpeisbgipnyu","ikrmoyqcvncjhmja","tgbkuvbbtipgomhv","odoammlvrqebippk","uyhpisnndplbnoxf","pmqepaligekvdrtz","gespahsjraygfvhz","wbqfugjszyqtrxml","zupwtalxkdurrpts","yzxjvxtwbyylcixc","fcqomkyudxhksbme","qksllfihmhfpsffh","rmxtpbrebasfnhnx","femnpmrohnevznad","ztrkxmpfapwuwpow","rcvnlliquevpthqz","rwpmgyvnczaqdvuf","ghzefkaemrgwcwfe","zjnnzkzpvtuezmzl","fuwxdkwhllbuhggg","eoowpcrcdcmxcjmc","zfpxhaqlfqqxhpjf","tnevcimojsxghwqm","dtsbwpepvhssfjzr","hwyxwmfliikdwhyy","zwlxconuvqduivza","zkyypwqhdlbrkggc","fuykrryrhdejwtlv","jhulamonxfxnspqd","fhovroxnjgtcqzzk","dhjezzzenqrkvhmg","xhjipbtofbojuotg","gjfteuwucqpplnkh","rderwdzdqunkfbkd","viqxablzapsxbvsb","vsjnmbuwvfudyyhd","ldzhpwecyxkgaost","ikdytprdsxkxmsdx","tqqlpoubnxuvxmns","wmitijzermuhhqub","lvbmdsykcbctybwf","nakfaefyryhdugpb","nofkfunslyhzqldb","fczxrvilhuprfpkd","qjuoeaibyhiuhqmz","zhtwugkzujcwysul","akmacednvstedirk","ggkftxrnvrziknsm","mhornofkiigainrs","atoutrpgeyditmlv","ggacbknhntwbgjny","zjhlojbclexbszrb","imznnvliiwesjrws","anklyaobmymivbgt","zrwabelcmnxfwbky","ndhqxwgmpoxphnye","wffgntautwhspltf","yejbuydinfkfjgzx","zsluuhnohnnarjpa","pjiniuqaevwampbj","hvgbvfovcphkgqyq","gfsiohnsnatylvhm","wyihmsrzkaqxespm","llsmxfgmuugdrqbe","aicttmcqzufdpzgi","tmeqcjssydlohmub","iugvrpdzxxpjwhpl","yvhhbolimcsgbmsm","nibfxhyglmecescr","obuebeqmfxswaehy","ltoswoigykivedzf","vaprufedwwzwuwop","ugzylkchtevxpjeh","cvrrvxpwgybomiey","iqerponimcgwgmta","uwhmpodysecrsfjd","gtxuiyapuupkgyzn","mzysuflmsqoytfop","uqanueoubnpwnymh","dafbmftuvnpmhlcz","cuvxvhmfqmreqrel","atvmxcoyotxqanys","xbnvmlmoqoiyhkln","citidgpkyyjxokhg","yebjuurldzdftzwl","qiqwhyajusjmpwql","lvykstamcunjpoyl","cznwlsyeaeayouxn","hjjjbefcxednyacb","xpqhcqxiadtjwobz","tcswfiixavcjabyr","rbdcvvwhsydftxiq","tdyuvlkooterahxi","jernlnierzgoclij","qwicofhqeplyykfe","fjogbxpvzwwsrpjh","uxritaetjljmnbrz","scethsnvpbamojxd","nrezrpkidjoyufex","dvwjvnishirdprxs","vndbibtcnqqhocyy","ginziipwuiigzgfw","mpkilegcxmniequi","bnzloelfayizyfle","rvwqrykuxivqygop","pazebfexjevmsjel","oulruggahvblquzi","jvhgekfigradwerf","kshxjzaavwdhkcfn","ikgacexlcgddizbz","osajmkuktfytrlyq","hbytssdrheygsdug","mkjgthvmdvupfjzm","nehsizhuhnhuizgl","gtchymzcesdbeuup","awqhxvmwdtyagnlq","qxmawvitjguunxrf","gvnkhjaqulhzugut","wcsxxabrhytwhrcg","lzvkzwvykjlfhtlc","ynchtxgqmiwwgvff","weoavpcjeogdykoz","suklflbingilmfuv","vdtguwydmikxusue","aasmejckplnrkazy","givmoqsjfnerxulh","eosrcyjewsruwfch","yztmkqrrfxgqmqll","iwniejdapxerrbwc","ghfkyibdbhxniuss","uaxmpthnvootxgiz","qwkawwteaodfmbyj","ivtnzmkjoculkwrs","xamdrljvixneqiiz","luwmrzgqipeobink","nlnqpnogksklwmty","ietuhooeslaopyrr","aeylqtvobgyfmpoa","oonxhdjxfijhoowx","kvsjsqhbvnxvlypd","ugitvhjohgwrlhal","xnqkzuweanygssqe","xhbwsaehskvltdwc","yfryyuopckttfkit","rykrdonsovateneh","clheccsuvyagnvps","itdmeublmxrorvqy","nkagiskptborcdlb","kvcimojljhstbwcp","xyziydfcexjqxzow","zhtmwicebbkiqcck","rnundrygltvznacs","etwvgqsujhfgrezr","qmxnnopngfyhhoug","oilcctpfnpxccumx","glzxuxyupspwsdfo","agskdtvmbxsojzsg","dizarytlhksvrtym","hggqrkzqzujjlaqx","cqalrcudmxedqdlx","yswjroxlelgnucmn","aeimsefhgnndebvc","iymqvkboccrhaptv","nazdkzivzxnzgftt","eskrtifsgwjkonmk","ghjqpnjjaftsdeka","cibjxhzmnjlutygg","bzhzstqrqadjzwfh","ztdognelpwimrzef","dcoqhoauurgpxwve","vahugvkrehfzxzkc","eudueqwdcdmanqka","jqxkwvlmjjkmznne","pifrvwwptkhldebh","nvsnjsvfakwuobac","oounghvgewkggjxm","rgpvzydoppgemoga","rckhyhlmmsyudjjw","pikosjshyyodbiog","eaaocnblxtaczaev","domotolktupupumz","wventofubrdlnakz","jqczmlmzwlvsgxjy","btezsnfgrwqrgyvn","lldequvqjxgyoldj","mmvzemnkuwxarjsn","pkwxrixyusffyqyh","pssudtatmzlihqdl","irgzsaabxwmbcpzo","amqnfjlddtmcwivc","ubhvgmagyxvjrlki","itvzbanbholuhxti","lofshyguprhohxzd","dijmfcgkpynhinzo","slwewvhtiufbfraq","siaspnvnrzowzfaa","scepcjaqsoqenmnh","afgvtzllcvtatxyh","wfmgaddjrdjjsrdn","ojoyqxtodbvhnrai","avxejwpadjqvxtix","ajeqvrkhzfotmgbl","zyhfmzdejccessuj","tapdsshcnkhtycrb","jqwckhuwubtvxfqa","gtwpyjgvfrtssrhj","fohwvcmeblanvpse","qogbdghdxdgozcxy","gpyqzuranyxxtbpc","nothclfgjsnvjykz","yttztzunimdqtiaf","bnzzkzxwgdjalcrz","xbempjvzehhkjthf","krwdiphrqjqofjyt","gluaqwxtgpcoqjbh","eyifyfozdtlfnjcv","yntdtsiykwlufosw","qylpoxjrmzdkwlel","ttzetkcbbltrspuq","iedtopdcuflthxtz","ttxuiwfcpicbxhlb","uccrduyfglqzkmnu","xhucbewnsmljpkgx","rwkhprarhodupyyp","cvquukakynnoiqtu","mugzrgedkssssseo","aqjelauzrlbuxruj","zghsjtfkgoqupyqa","aukbjwzevhhidnhu","uajrwmdasndlijue","gzuqtaxzgwbylatt","hewthiawqgqormxg","jquuwzeebetofmfy","bsnrptrmybaxgyzn","iwrzdhwhyercmuoo","jhxvcniwglptnedo","ebkarmfsenndxwdl","thxhvticqizacxvv","egirwdaebemnfkuj","jzizthshlzsxjvqp","dpsybhaylkvskgud","nczuegxtanyucozy","rkusdwmtfjxnwhyn","blctjcnecbupcpdg","xnrddxotaspyiqfb","pmxyasqmuyoynahp","qoknwoyqnptroqjj","tlmjpyzdnlrfhbpc","ohmjadvrfdwkbfun","rdumhqrmnpzrzhrt","lilxqkuuyhvorbnr","jjpzmibuuhjikwsj","detvkemurlkrzxyr","eqaugyuvxjxfnehw","slbxlufclqzlsamp","luxqtwmqooyoggca","jsyfecxgmwawgurl","hutfcesyeajrgchz","ayoshrepsexrrdli","zyighqszkiykogzy","gyeuafgwxfinldrk","yypjyxyrmhulmuie","kddjqdlmkfovhntj","gshxeaaggbfpedgm","dewoypyldpmkngvy","mmkprtzvyxujhpgh","taacruwrjtwemsbw","hubyynlcpqemzfpf","xiqzsfiwoxwprnun","fxfhythdyhmcvmbg","padvgjmqgbambzve","nzcfpaftpqkrzwbp","zevsmoqwhdzksvqq","pubilrfexhmdwyac","wetzmdqcrcnwwgcs","keoxoqxttvypszhg","awqyecqdyrlnfatm","yqcidxznutgzbgmx","uvhaziikrjzpksal","lrxzvtcnbdadgycc","ylnrrfoqnblxtwhc","ohhtefopbrzxqdml","gjhpcubkgaaayusb","ipqjdwxjzzbodxmq","hkprzcdplspzioep","hhssplmguixqjpuq","vwtrgzxqytcqeezc","jfbuokepgzwsnjzn","lvhtpzxvxnjielfj","uoeaxabycxufodtp","mujzsmrkqrrloxnn","icnwmdxkmtzfgzlf","okxgorqullwxdomr","dhzickiibcrobgiz","tftctgrmxufxtjrj","xzltatepewykhlsx","gbiixsddzsfukhsr","bfgryymypjaysmgz","vtdpyivgisjvafwq","ftitfhlvfwuiwxcj","ikfxlsnhyfcljbuu","nlgwkbjmwqjyxwlo","lqpqskkprgkvlysp","ivtuwzhizytxihab","iglhlzryoizpatxm","dtrmxpnoclmxgbhs","caboenwdgwvmjxac","ebrdtxyshogziwkd","hpwfyvnkvanqdpso","ldirepfbkuxqnsdu","hywqayvjjqshbhcz","etnvaiqjcnxaobhg","jaudtvolgctoearv","fncqslqdnurzyzus","ohfdpiskxavapjmw","axxdtfkvdffxcfon","ljddvzdfccyzbmsm","iuxerllezjywpldu","pnitpfumhtdeyhzo","bhxpjzooxhvqiita","sxudsvqvgxxnczop","cgnhvcxtgfwapklu","xhmyaizqhdiyoljp","srpfpihyfyszjowo","wobywkabpemokjta","ymhembhbfoznzjul","slkhfhhvposeltgw","gtnyfcqhvojvbuow","ztndgdacnjjsadnc","afulgxahpptzsggp","dqllckqtoqwjvrnc","unyhikiknqaecngm","xbwgnfmsgqhrskyq","swfdubemispottwp","jfnvnqgkywyiaijt","wceyrpgtriiqhpsb","zclytzdxjnpnorzc","upgwblwztggrizvm","cwixzvuootsfcvqf","gznybmrjchfuxgnj","cpdpivrqhomlpsef","oaysztrnhrffupmk","gdvvbepuwjlnccyx","dhztfnmvskcmiank","ubwygqknkplwgmtd","cndxkfsirvjtyuoc","fqvxozbpindgtpvm","qiwhnarlrtzcjikd","ynpqhrihsrwhjzlg","rxcqftbvspuaydol","uyihqmhxpcnwegln","bpiiudnzpsylwovs","ufuilcjgxijjqrdi","qvbqhltatbguoatu","sgkgbodrpqumzhij","ddftxlzhmrftnjes","kgetotuvdipigupc","sdlgnyfsvrcnsgdk","xwnnttwpsgakozkf","twejvlpxmriawzjc","yqbmsltfzsivghui","sjdprwyxkdkjxdiz","lyamsjbcubssdjpi","fkfhoonjtokfrvlo","tqflvlubqtljwyji","dmjeohspwenwecwb","pmtgfbwzypfmatuz","hvtzorfovifqemnx","skqpmwphjruyerjy","ttjevloeqqamsjfr","osujgoxewrvcfjrz","htsdyngscgfsmfxy","adhqonimhzqljinx","pjnrxbgqiwsdshjf","asaksbaeremhlmvf","qnansrftthwmwjjc","sqfamchavtkelsbt","trjxldqftztrtunx","dolvmgerxmnwwsyj","ujvyxsaykpecljha","kqbbekbfeyjafqqr","jmxlqqcbrjrzdjwi","ikoyjtjnhhaiyfbj","oaaslpkprnfeodab","qpznfrvntmauofic","wevhambyxnbsrexd","zdybmsmfooqwnxsn","xzvbyqdlcuiqemdc","advcviqwldnhkusz","sssyxaynvsoulzkl","zcwgfjokwikzaccq","xwymeeilscpwjtsb","qzrqurinubnpefrl","ghplvcgjievqybgs","ebtmkraxrbeayamp","kvljalsppwdmumbp","ydfolufqkvljwjcl","gifiplgzwrtmoydn","agyubxdhliyxlebv","gmycxscjayqiokrr","ojapuifttnpdbqum","jsrcnbludsfqesri","jfxxymuflnomiqxr","gzceqknfbqlbxvbl","wffqvrsghpaheooe","ziikswxozjbtclfa","gheqejjkugpxefcz","fholhnztvxgqusgf","fizakkalclvexwml","nzvewiegnoymvdgk","bzysrtumrmxsytxk","obepntskfjuipxyf","yjzglfqfzbokreun","ehjnwwhsowxfzhcy","dgrijybhdmcerwpf","davxvcrmrwxcspsa","llalguagqbljrlrw","rfhhcoxwdeycrwvf","trefsfzydchnegwv","qdbygxkygftsneyx","udcjpmarjtfuuulp","gturoqacfwujsfnp","ayrvtqfgypgdvdfl","ogifxnesueedoxqr","rpthwdknjjupekdj","ozanjjdpqidkmzlv","mdxbtyxhffuhsaig","jghbtfehjlpiyevs","zwxseznfwvjbqgol","xpuyzfhnfmvywgyp","uvrrwintuirkfspk","dftnmntqtrksnouv","wmhwvynwhzxxtqnu","fwnbsobmirsgojmc","xgtqctfsiymtsqnc","hrxldlxfglxdrzfw","uqsrwvajebqswlsz","pktelsqurnkpqwit","suhsqurrcbmqmimf","etlqnbsatgdllead","sxkceoowpkfrrlab","qfhzyyhbpxvnlrpy","dkdrhicfyhxstolk","fdtdmysxfsydsuvc","vrieznrhiyigcwsy","ojlvpxddqfaxxodn","bctoenrobsyyywgj","uawhfqllddqnsymr","gqobozkaoljwdnmk","baxtybgbjgygxbnv","jomciyrcsklgqyla","craqulnxctckqcrz","ddsrqxqvgcyfewpp","ueiizipwzsqpboxn","uqnddbeznkejzxwk","sepmwtrtbejzhsdh","gxiioucwdarbgwks","qqpxbseoazdwajxf","flkzkssqwlkfjcze","aolglevypjhauihn","lnrixawfaypynfte","zxjxtwcgnwxcifwy","uzkzzjhtdwcacyzy","foqnlilszohwffzv","sqhvethvufzfydwa","ucopkqeidronwpeg","phinzjxdogyhlbec","lvbksoxrembbgmul","jlgfwdwscdkbrvby","blplipribmwrmfsl","lbveabgnjclkuqql","afmvhabtrezxvrzp","vgdzgjvkkyxhqcoq","lazeelvvbncxtmjj","orpnwzzddlacvmuw","vsfazioelugbarud","jvkousnxmaiutype","afjdigyzecepdfsz","bwagvyngmntoosgq","iryaigqvzmcuslxi","hbfhqqfvdgkybpxq","nzwccddcvtqepudi","grjgxaxxizglyxgb","jjumbvyxkbqberbp","qnwfqucddedaduen","bsvzdhyfyomzozpm","udgettbbfssiexaf","vhkeooqiwikvqnit","kvkvkcjcuiafdpdd","oskptemztedbrqcj","axeiceowrhnzaghl","oxepgmykotidhtjt","rxedrcwdxwaxpave","gvvbgekfaneimwmo","uhtingmjusuhicoz","avwrmqwzubvcdkox","gispnuztdgibpanw","neagggodcwemnctw","cpxdntwixswhgrtu","xaqsnocafuamqqrw","isvoxlgnvbbkmhma","gidbkvvtdcocznfx","jsrwtepnusbskwuh","vxkcyjvaetbfwlrs","pnvjozyonqjbeusm","fkjkdxmmgqepaunv","nugdbkhlsoqkjdly","smmjfqbeallbufws","afbaqnvzjolkrofx","rhyicwoiklpccewg","zztuyybzuibymzwr","ezeatknjkzhntrnw","lhkkawhgrzbzkgsx","sshkdgcfoaimlhfy","kutzjbkmkksixkch","ridiubuoaxakpyhz","ukhljtjibhtpvfvq","xuqejragiveeexvx","apsjqqikxicqpsdj","ncujzilftkbyyfif","qajmzdetyndvorkt","wnfibpauzrueswli","djllgaofivspilbc","kqhacrjigmqidvoe","lrukdfedvicbqvgs","pnqyawfqhiisqjyz","egvwmtdwtfdzsqwm","slrqtjjcydakqfhk","ahrmteycomugbvxv","fuasbjndoesncsyj","okurrfqpfauicuxf","lilccpawmjpdrhpu","gwubgjiwwdtxyrlw","xjgmyeinbgolngts","rtelshyqzssonguz","syaovaardzxeshqq","snfezxwyteufqyfd","sxnzdjslggnhbfwn","huztfpcbgicputwd","oasgwohszcjewltu","yzklorgliroqhpfn","dgxetcutnpxijybh","ybrbopmmicbpxooc","yyuayhgcxkmbaocz","wcqitbjbnbvzdvuv","njtoqkwawahnrhaa","jjbnckijthkgvozt","zgpjcayurcymwydl","yoygzkzfzgqpfqdo","pwaqwieiuymsvcot","hijsknygrxvgghqi","zefqjonzalazmunw","pxlkgfkqahfwiqyy","kjhwvpmynekbomhl","pmozuzlbqriynmzf","afvldopomiwtiock","ucrowwlzpzdpnrks","aknoivpkjtraemft","phweeboomvaybrfz","trxnerifjgqsoukh","ksaqbowrlewqqgug","riphyoqjumnobwjl","sldkykxsddhbtaft","wbfighuwqoyemebz","azeurrtgmyhpqgzz","czuyhtahyyhyszid","bicbqgywcuvxcfgu","kxlgjllqaiusfsgr","uiuegtojvwlxonif","liitzirntzgkgdyt","yypkejvpokvyodds","ycfwiiyeoztfhbqz","fhovjoeljjlobehr","afmjsyhxxjklunxs","xxthkxbphutuisaq","lbqpiyeprsimgeyx","vxyggjgnayauxves","eqwmgkiruvgiuqcs","rzcuzlxogvtwslpe","vgfkllensggulrfl","uwjqrwglpkljvjsp","brjfeyklcqqmehbu","cjmvuuleymhmtpnq","sejbbbxblguwmkzz","zcbcpiegpivrmroh","mrlecwasqkbfguou","mppqvzhyubgfzgrr","nlwfhnkcblwxynte","toqdgocqdisjbcwo","ofeplwrgnqjqlsoq","ogrjwlvvzlsvzigt","yeibofibvmijuzjg","oqhwzroikxgrscxg","tbvelfisjzvbnypa","kqwrijfmqacwjcts","pjvbirwwiwkbgpts","akbffxktqoaimilb","lkmfjdfldvmlvomh","aevucpxzcnpshxcp","koexwneuibhjyzgr","tufockomecvnmipy","bfmcofsuuayooegt","zlojhqifzjufncyk","ssoqpjdeoqcuesaq","jzrnnfikoexpmtxj","qsvoxjbiprfdjeor","monuqlsxbteduorj","suycnpwvgyslwsio","zqqlwnveckifmgot","awhqpmjpsxhhhzaw","qhhepfekqllmchzu","tlvkhbgohjthrack","wsjvzrybkdnawkfe","rgxqwfdhbeoikkwx","vofjqprjrdjczodl","utbfwpikrnmwebas","yheqlbelswlbfujn","jnmmcycbygrivyms","osofoqzoexvapdpt","etpwxtfinexezhef","ltthrvrexefwoolf","gqcwuslbbxpdliqh","tgzqjdwmkfiovqeg","iexyhlpnvoezpqjz","dhdmaxpwwcxdcozo","yuizceyzsglhzylh","txbfahpzcuvwpemi","qjdfyvpyvwnkejdx","emhacrlyqtnpszfn","sutrtjaghafvflhf","damzeabjydtiajkq","zrtyvuboiovhdehi","ufyvwaztkqanrqiq","fcithuvfmzloqlob","dwzeqkdmifjjsuih","uenjgsbvjifeavvy","mdpsqrmfhuzhyzom","edjurqxexspnlqqr","jiitmovlvzgiwjvt","fljjlaudvbsmsonv","snzbalnelkjimdts","ergnrttrpilqjhha","gjourejhtplufumt","qsajbfcneouwhctx","ztjuwctcnzipklpa","cxyugmmqkmwplcid","jwjujcpyexqthgta","turzobdcbwifikkj","ijafgwaipdcotheg","cfmenqegbpwczzfl","aktgxxjixzhlsbab","mhgfgxegdwdeqlyg","yvbexzqtrznkbbul","cgkfzswfxtfhntpc","koiurdxlonemubmg","lsceqyzzhhldjwqr","kwppeguhctjxxoxw","hiwtfvwbpozxinqm","idoahqoqofmpsohi","ofbsnwqxwmbjbfsx","bucaiadboflbyexu","qlixwgogxrbdnujp","upzxzezvdapqggxv","ttuiaycxldldkmfo","mmprmtpxgjolsqgn","mqvfgpyrsznldywy","uzsiejkaaejcxyma","znjlgjjqjkeqzguo","rerkhmxznmpomlpt","rxxurkgmxosfcloc","gquuhvssjcahahlu","ymqhclvylvviittv","gfgtyanmujjgmzxl","jiywwdocfhvqlgdz","buslanrpgtcgvkyd","sgngeargpphvczlq","rjlkwrspkeycqqtn"};
    string s1 = "abcds";
    string s2 = "dabcss";

    // cout << difference(s1, s2) << endl;
    dynamic(arr);
}
