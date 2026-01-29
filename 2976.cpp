// 2976. 转换字符串的最小成本 I

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        using ll = long long;
        const ll INF = 1LL << 60;
        
        // Floyd-Warshall：一次性计算所有字符对最短距离
        vector<vector<ll>> dist(26, vector<ll>(26, INF));
        for (int i = 0; i < 26; ++i) dist[i][i] = 0;
        
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (ll)cost[i]);
        }
        
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // 直接查表
        long long res = 0;
        for (int i = 0; i < source.size(); ++i) {
            ll d = dist[source[i] - 'a'][target[i] - 'a'];
            if (d == INF) return -1;
            res += d;
        }
        return res;
    }
};

class _Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        using ll = long long;
        map<char, vector<pair<char, ll>>> dist; // original -> n{to, cost}
        for(int i = 0; i < original.size(); ++i){
            char in = original[i];
            char to = changed[i];
            ll co = cost[i];
            // 构建有向图。键值表示 in ，值为 to 与成本 co
            dist[in].emplace_back(to, co);
        }
        
        // Dijkstra 计算每个字符到其他字符的最短距离
        ll res = 0;
        for(int i = 0; i < source.size(); ++i){
            char in = source[i];
            char to = target[i];
            ll d = dijkstra(in, to, dist);
            if(d == -1) return -1;
            res += d;
        }
        return res;
    }
private:
    long long dijkstra(char start, char end, map<char, vector<pair<char, long long>>>& graph) {
        using ll = long long;
        const ll INF = 1LL << 60;
        // 初始化距离
        map<char, ll> dist;
        for (auto& [c, _] : graph) {
            dist[c] = INF;
            for (auto& [v, _] : _) {
                dist[v] = INF;
            }
        }
        dist[start] = 0;
        // 最小堆
        priority_queue<pair<ll, char>, vector<pair<ll, char>>, greater<>> pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (u == end) return cost;
            if (cost > dist[u]) continue;
            for (auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist[end] == INF ? -1 : dist[end];
    }
};

int main(){
    Solution test;
    char source[] = "lubkbedceapwmdzflfahbpigowtbewzpwqjxgzzjwkjupuuxuvkneityzfnrhocmmcsmxatlcedpqxrtmatardjsycyptsyonkbsekmtmxtjyufhrgpzdqujztkwfbvsfzkzoyzjwuraedxywzvlfyfjdttnfvpypfkmiyziydzikhuwbreuadfnrhcfcqhlhmbaouwhhmwbiamqcpaxqnlrowgcwerijjpueahtnbzlrbuphtauwdchxwefasywmjqfqmwaurnzxcbxtdzvmfflkgmzajsfhdxcqusbxyghzpwjjwrsicirfuhoedyzfxaciyhawniekxgusjwghbbtwzvwqrlvhhvqvokupkfprqnlsbckpnozplfajusrdaoxrynpkjbgljreyfbpmbwpsgbbepogaxezlgnoaqeaeymcjmoygskzaaevoevasuityguqqauxizbapkalcjcgqmdrachknlzifvmduermmokqkpcawquiqhnzkqvevipitgahebctbkuzvtnanvneffwkencrwfuokxpucoeqhlscgrxiryktdayxjzfusevmrrezdwrlbyhntdwjepssvafwopdpaqgddslqrzmorwtotoidxtlyzqxvtohbrcxjfjkdzcgzphmcwxwbbnfqpykfhvmbfolwbezqvigtnrqwrgswtcbitvixgbaexzvgaqcpkckqxvasnpnkucidsypxgilkjctpwbyzkioavktxsoikblntiefizfzoqpbiapxgfvdespxrhmnixxkypwdtgnlzldnxbhehsfhynpiponxeubjvcykjjupvtvyynkhgtvtgoqdsalzsxlssgyvpdyplcszqyhorwsowtinbwbekggbrbnjvguprwkapwufnsbeokmwiyqasfqjnkwpsyaxsofkvpighkjzhihxchpqmormfxijnhpdpznphvgnebodgbbrmyabcuzurcfntdytktqrlzthelazblqmxwyqcqxdolojytuipuqwrtgawlbzewwqvapmqjqyfvrgvpqyzpxarviscfcxmcamtstpkmiylnxptzntflitwupccrcofalwubeqwsfulbfxcfopypggnabkqjfxxjbskrdtidicuzgaixpmrzygfxqwchczkkjfwszuxezqixuabcvmohjdkgmeqiaxhluqoitcrdpeeuomklqmggsxwrpsrclwjndsycesvywyungaspmbnsnfrxakbhxdplfowsxkrplgeirywtimkljbagecnuhumgvualfsxrposdlwiuyqgjxescccellmsdlxbysdycmmzdamqkmbcyoayqtbaickdglveholdfmcupqqtslidlabksjzjoshvkeaysvkrcqbbkxalgmqsloyedosdyrazmcbpbmomppofiotpjkynjhcmnssvgaokpkrledoxtmhrsybnspqcrgzdsjmpoetzquuwnhhgpldinmdwmtxaxazzcbawcuhlhkewhmgpndcpmqccpyspffukkaopszjbmrupkchncxfpspkcldlqiyhpvtodtvsloyprlkzosisnwxpjrqizosmsbozzchhrryojvdimbyzrerrajfiqcwxauwqapvcuifugmxtvpovcuftgkesrhznbbntempzcvngajqgdfkosowvflfvgzfstzlprmxrswrkmawyhollegqeucnbtohtvanbivjvxmwtcijwnpthrobfqqpbnyeixczecbsriplalxzifomdqxttyfdsscbwqswvvtzcwksuhmjavqxomwhvkjrrogojzftpootwgaerdcjdmrojluvkczeuvezsohyknixhkffaxnoprvpqtlkucnyaujegezlsectuocmsbeivynihtjdnrwdkfbccykcuebpbckyjrdsmwhbvsfmbdsfixahyyorljzgjvrxscpvvxvrsrrcczwrcmmybjvlwipuvdqkyv";
    char target[] = "rpwauqhttpyhqvmbrfzeocquccudtphufrrldnivcrvhxnnvdpxfmtnazklufbicwbziyizgbafbhhbpyfaarujkvupiljmqaeekqifaqmsfnczxbiaxoeloxcbddzxtxwffwqwgfkyctjdcgverwktwrprtqauzrmmzpiflkmyfnplwsyndbhudkgmvonpbnuvulshvceshwvmhrgbrvcxpekbdtadhshgqfqmindpswdhcxxuumqpgjntuiwxvyvxlpziwierwbmkibyqzbcrsqeavmkhaytjplhejibeislnnmmslrsvaafpskpyvltsqvhrgtennuhnvymhzpbyjldgawgkxakbmmazrsnuyhqztujygidyimbciknzmhlbohkswuugxrhyopylmpucdpcvqgidsfbciwyltdnuleaadopzieywuikpfzagiprukyvxsqtdqlkukjhnllxldbfyiyhdsffuueaceagwhqeqhbcddstmbfheathtfijfoxsservmxpjttstkiicyjmjjcoxlvkfqwvscqutqexgaowfpwomdmaucwbtnvgspdacqcicpvkmjmvtumhqovoedzgyqnmhiurcaixohzdnehnrewmmstogtikmfaglllxlfwbmogmurtluubhebasmxfzymmuibljekzncxmifctskrvsgmknlbezexsawmyzdfwaibqinpbwcdipzlxhstbzprrwwnyzokenijeqwwaggngosjyuyixgwqhehofrvijaufhtexhdfuxbceqrvbrhxjfkeduymmqznlvskmhqiywvpzaajhmpieprlzwoebohntxnctxhxaecnnkdrvhjlbxfxmhnlfnrxyktdhhmvuorkbwfidyxuavzkqozbqtxfsazwsaxjmhovtfpspjiexfifjxctxzclplwzsqqaoegpcgpbbzyyjevothlsimpukimwsnsijhfpnshwgpmmhurodvapylovmiantipvgxhbvtbxpfnrvmvsaeuvzcojnsstsszwqzoctwomcaelstggehxqlyvwhdrjhvgtcfqqdpheycifglkymdoxfruwlnujlmzbxjsxxvtezthbfsimjkswtyreylzzzeaqbtjmloeohlmcuhzuxkotykdfuyjzlyqzyjvletpvziuitmcuhgtsczbvvhqjlnduvkswxbegtccsyyptjnslrkomctkxvsdbddhfqrjhcykdwklwlovmtbnqfofkzdqrskgdokgglwxwstxrigitoxoonxkwhyscgdbicrpwrpdrrrjxolqvixjzdappgdbnwyixpqyeqaplhygiwjxlbyexigpanqjxttxxdbfdkzshbyqirnjxmgfjhkngotncvfskvbtjatxuooyhzpojfccqlcdbrgmudzejcyorvyontvqtvjmqdylpgtptdpzvdpnehluvpnlrizlnazmuailxfhfeaxvnhgccvfpmnzfquwfxzwcafknmuvynoqttmvwvfdnbynhjbybwykseyhpzgnizsufgwxigsvaxtvwlfabqrhjwplkfdphfsvgucnuvjdcphabqiqlmvnprcnbkfjkombfdasvwtptofvnamryjiqbjanyvbpufddpftwyxjevluvempplsrksvbkcqbswlnihyljppbrylzqsenxfkvjypnnbpozgsxgdsshteirmlmfmcwktspeklojpqedwmubbivagdgfztbikazayttfdmrkwlicdhgfvaccfhvggzhvryxmhfqltqfskooqlbjkfyzdgiugthogwfaanasjfftzggahxmhpasjgnkfjuvcobwbkpuofzqwxhesxclhraejfyajledoospgayefgmsuxhgnvwikinyxqggwbwclsylawvzjohcxdjwxmphgritpyrditbztynnrfqcyfqrlinfwpmrbwlndacvmrxpspudgxikcydqiiakenxrze";
    vector<char> original = {'u','b','k','b','e','d','c','e','a','p','w','m','d','z','f','l','a','h','p','g','o','w','t','b','w','z','p','w','x','z','z','j','k','p','u','x','u','v','n','e','i','t','f','n','r','h','o','c','m','c','m','x','a','l','e','d','q','x','r','t','m','a','s','c','y','t','y','o','k','b','k','m','x','t','j','u','f','h','g','p','z','d','u','j','k','w','f','b','v','s','z','k','z','o','y','u','a','x','y','w','z','v','f','f','j','d','t','n','f','y','p','k','i','y','i','y','z','i','k','h','b','r','n','r','c','f','c','l','h','m','b','a','o','u','h','h','m','i','a','x','q','n','l','r','o','w','c','w','r','j','p','u','a','t','z','l','r','t','w','c','h','x','w','f','y','w','q','q','m','w','a','r','x','z','f','f','k','g','m','a','j','s','f','h','d','q','u','s','b','x','h','z','p','j','j','r','s','i','c','i','r','u','e','d','f','x','a','y','a','n','e','k','g','u','s','g','b','z','q','l','h','q','v','o','k','u','p','l','s','c','p','o','p','s','a','x','r','n','p','j','b','f','b','m','s','g','b','e','o','g','e','l','g','o','a','q','e','y','o','k','z','a','e','v','t','g','u','q','x','z','p','j','g','q','d','r','a','c','h','k','l','f','v','d','m','q','u','i','q','k','v','e','v','i','b','k','u','z','v','n','n','f','f','w','k','e','n','c','r','x','q','s','g','r','r','k','t','f','s','e','m','r','z','l','b','n','w','p','s','s','v','a','w','o','d','p','d','l','q','z','d','y','q','o','r','j','f','z','z','h','m','w','x','b','q','k','h','v','o','q','v','i','g','q','g','c','i','v','x','a','x','q','s','n','c','d','y','p','c','b','z','o','v','t','i','k','n','t','i','e','f','i','p','a','g','e','p','n','x','g','h','h','h','p','i','e','c','k','j','u','y','n','g','t','s','a','z','l','s','y','d','y','p','y','r','w','n','k','b','j','u','m','w','f','k','s','s','q','f','x','j','o','d','b','m','n','d','e','l','b','m','y','o','w','x','c','i','y','t','t','i','c','l','e','x','p','g','n','q','j','j','t','u','y','w','c','k','s','u','e','g','m','u','o','i','c','e','u','l','g','s','l','j','s','v','l','i','h','m','v','q','g','l','l','y','m','y','y','i','d','h','q','l','l','b','v','a','v','d','r','i','o','t','n','j','h','m','g','e','r','d','s','t','w','n','t','b','c','p','p','b','h','f','v','d','o','y','j','m','h','r','y','v','i','a','c','j','f','v','m','m','l','e','j','n','t','b','x','o','t','w','z','o','i','q','l','u','j','g','o','c','e','b','d','h','r','r','b','d'};
    vector<char> changed = {'p','w','a','u','q','h','t','t','p','y','h','q','v','m','b','r','z','e','c','u','c','c','u','d','p','h','u','f','l','n','i','v','r','x','n','v','d','p','f','m','t','n','k','l','u','f','b','i','c','b','i','y','i','g','a','f','h','h','b','p','y','f','k','u','p','l','m','q','e','e','i','f','m','s','f','c','z','x','i','a','x','o','l','o','b','d','d','z','x','t','w','f','f','w','q','k','c','d','c','g','v','e','w','t','w','r','r','t','q','z','r','m','p','i','l','k','y','f','n','p','s','y','d','k','m','v','o','b','n','u','v','u','l','s','v','c','e','w','v','r','v','c','x','p','e','k','d','t','d','s','g','q','q','i','p','s','w','x','m','p','g','j','n','u','x','v','x','p','z','i','w','e','b','q','c','r','q','e','a','m','k','h','a','y','t','l','h','e','j','i','i','s','l','n','m','s','l','r','s','v','a','f','k','p','l','t','s','h','g','e','n','u','n','v','y','z','y','d','w','k','a','m','m','a','z','r','s','t','u','y','i','y','m','z','l','o','h','s','w','u','g','y','l','p','p','c','q','g','d','s','c','w','y','t','d','n','u','a','z','w','u','k','p','g','k','v','x','s','q','k','j','x','d','b','y','i','y','h','d','s','f','e','a','e','h','t','m','b','f','t','t','f','i','j','p','j','t','t','s','i','y','m','j','j','c','o','x','l','v','s','e','a','w','f','o','d','m','n','g','s','d','c','c','v','k','m','u','q','o','v','o','e','z','g','q','n','u','a','i','o','w','t','g','m','g','l','x','b','g','u','r','l','u','h','a','x','z','y','i','z','n','c','x','c','k','g','k','l','e','x','a','d','b','w','z','x','s','t','w','o','e','j','q','w','n','g','j','y','u','y','i','x','h','r','j','h','e','u','c','h','m','q','l','k','m','w','a','h','p','i','w','o','o','h','x','h','a','n','n','r','j','l','b','n','n','r','h','o','f','d','b','w','s','o','p','j','f','o','g','p','b','u','k','m','n','g','m','l','o','i','t','v','x','a','g','r','q','d','c','g','y','f','j','b','z','f','m','k','y','r','z','b','o','u','y','k','y','q','y','v','t','s','j','n','d','v','x','e','c','p','r','m','t','d','d','d','g','o','x','w','r','r','z','p','b','l','g','j','e','g','j','k','h','q','r','k','o','c','c','q','o','r','v','v','q','t','j','l','z','l','z','m','f','x','p','q','a','n','v','d','n','w','s','j','l','h','f','a','v','k','j','o','f','a','n','e','h','p','z','b','g','i','r','i','a','d','t','f','f','z','q','j','k','h','j','e','a','y','f','v','j','d','x','i','r','m','x','c','n'};
    vector<int> cost = {495880,777062,860366,991169,918213,999861,873269,758283,781572,842657,928123,880838,277934,695961,664858,824511,863668,766476,777617,459707,809834,905975,472267,482695,768708,908236,886212,973444,457016,686022,723838,873129,893464,560042,981867,776790,915870,903051,906967,851950,499532,977470,658980,882721,995750,642827,895721,921991,528538,947602,932186,491080,386365,918571,644337,102641,352595,863021,960711,767649,781770,988534,712948,965803,630937,989273,921986,726648,918919,607125,804344,901851,773592,900617,873356,900400,926296,654151,299765,885439,951264,809360,859469,698963,869335,774712,947882,992000,953691,980676,889711,894148,856859,166960,874471,222912,784068,967888,994172,645242,167732,819458,609714,976178,930992,983044,705630,990116,922226,775269,958766,934193,828885,953356,418729,505362,836960,949547,346032,696057,478813,268801,284173,920516,771600,941571,950010,635421,582117,965993,633177,975381,974177,997949,832444,936698,759363,884830,419633,999827,861416,924744,702593,631744,843936,933024,662908,206473,678976,697666,925661,626270,819840,900129,689541,777601,745067,863889,569931,692147,601077,591724,876345,649309,965511,894233,980580,965552,466512,515399,955977,757064,328513,658312,700805,574198,862139,135718,933961,891942,658342,949986,785144,791885,829730,871575,601646,866047,925593,943102,887917,813704,319663,818113,851981,994901,640909,712259,962858,459165,921087,964558,882971,999542,846592,662464,848575,868488,746728,990886,958189,824614,989962,702795,738547,652755,770845,929618,821126,947788,697426,894212,662514,634978,707547,966199,949124,769636,984457,766607,855782,997602,784864,840521,944659,972097,932684,936045,663898,944149,988935,527026,840589,690628,897107,659761,533795,476088,699356,920378,900016,497776,900632,995566,426549,894313,864577,552214,802211,996806,668785,822353,591073,207097,632967,561586,280419,926545,922201,966717,532738,303795,908766,659925,743976,945024,833438,972121,671901,804124,898444,625747,995867,652490,686214,337829,679296,585433,561722,838593,532753,950865,327568,979668,853310,985201,863445,819483,849401,996972,339282,997782,735436,997998,400298,725501,848133,960403,989684,814274,917400,628814,291026,531156,487171,969867,998326,989855,377642,915825,633439,972651,993826,894647,921590,895572,998288,863371,980781,679668,637225,559690,788225,767960,408333,694926,984079,855062,508637,787941,638892,801974,819751,992694,997747,954535,997806,851157,900017,921422,358552,653482,996173,906067,933856,701562,808262,396186,807915,728497,877766,934024,857237,878820,808972,899537,814642,966223,823527,923249,729386,737038,946307,992499,681693,851849,911842,622656,993770,682601,873141,922881,886886,936771,998373,407716,663363,982041,871114,789305,974511,976548,664099,500594,996589,993166,882231,865261,989878,853594,804968,986442,556271,244319,632245,890528,665225,560072,862188,839715,787174,778004,464953,904224,518293,885070,611160,604327,877708,909196,870113,897062,179000,937529,916177,569166,999041,690149,671958,928039,945964,329331,659526,988998,481595,999683,959989,893516,903539,993730,856274,646161,933956,777008,904084,264449,402400,755811,845673,910981,856400,770873,488728,721909,732261,950872,831313,806714,402261,736643,318843,958779,878504,921551,753974,634914,875444,836170,873465,983526,804813,960124,996151,959171,979094,904273,662081,263752,244858,982167,684246,18077,428268,584601,923996,909367,590347,261407,880119,626280,631904,943044,738714,866392,435951,470469,744258,944180,996360,797319,809027,710604,711462,373223,897504,856823,303343,897201,307454,683358,478622,749195,889556,990157,743137,745096,893723,838967,886739,739903,899445,715364,945478,906067,877428,788582,763871,377134,561783,169021,857534,230601,970907,368575,435067,993130,976316,986947,677345,930533,957118,466350,996463,782866,941075,928642,905828,227871,710346,974279,949697,557023,952006,992248,957572,984936,915584,827847,978388,787817,942988,998558,946832,973826,731286,625876,853985,296329,846075,968612,984057,736780,80394,973160,911482,777665,121451,625318,963615,949158,965027,960174,488483,976944,717264,882458,960536,912458,934193};
    cout << test.minimumCost("aaaa", "bbbb", original, changed, cost) << endl;
    return 0;
}