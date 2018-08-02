'''
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
'''
class Solution:
    def checkPalindrome(self, s):
        i = 0
        j = len(s) - 1
        while i<=j:
            if s[i] != s[j]:
                return False
            i+=1
            j-=1
        return True


    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        # if length of two words are equal, then it must form two palindromic pairs.
        # nxn matrix to store
        output = []
        n = len(words)
        dic = {words[i]: i for i in range(n)}
        for i in range(n):
            each = words[i]
            for j in range(0, len(each)+1):
                strleft = each[:j]
                strright = each[j:]
                if self.checkPalindrome(self, strleft):
                    reverse = strright[::-1]
                    if reverse in dic and dic[reverse] != i:
                        output.append([dic[reverse], i])
                        # if reverse == "":
                        #     output.append([i, dic[reverse]])
                if self.checkPalindrome(self, strright):
                    reverse = strleft[::-1]
                    if reverse in dic and dic[reverse] != i and len(strright)!=0:
                        output.append([i,dic[reverse]])
                        # if reverse == "":
                        #     output.append([i, dic[reverse]])
        return output

if __name__ == '__main__':
    a = Solution
    l = ["f","giihhaafhebggjgb","ddbij","fhdhfigjfbbefdc","cbbfdjgbdcffdfefbf","gegcdibdijfhhe","eaijgddhf","icijchjgffgbhdde","fbdghbcgahjeh","ebaecfgehabedec","fjdchbcfdedgb","eec","efcagidihhhb","abbgchijajdbidfiig","cba","fcgcjadidcdef","fjgchhjjcicdfih","bjeeiecihfha","bgde","cddgaghge","feacbh","bidcggcdajgefeehjg","gheachjddddhgbeg","jaddfhfc","debfbbici","jdaffgdegi","jegdaihhea","bbdhgbegbgdbda","acgdacjcjbhhae","fc","ihiefdadjdfjd","dchdfcadbegeiig","bfeffebadjchefjce","ejhiccefcceed","fgfga","gdeffdcehcgfdd","ghehedchdejgjjg","gbfeccbiidjgjfbibjd","a","bfahedcffjgghidbheej","jagfaegiigbjch","cgjecdac","fdecabedajieeadafdc","ebebcbf","aghacjce","gdiiggcfghabagef","beh","fgebdgefhedgfghhddj","ghfbhcccbggfbhcie","ecbebjeecajieb","ffjhcab","dfbchgbeafe","ecjbjedjddifijibee","cdddd","bjhhib","ebjbeheg","fdaaihejaaf","cgiiaefhahfjebcdicfa","dheibbefdcgfgdgac","bjcgebahfbhe","jhdidghajgcaae","icgddfgihedaa","biggeddigcgh","icjdd","ijieji","hfeegjdibcebagabe","cjdafhfgfejei","if","bcjjc","efchjjigcgjf","efejhdbie","igdaejfcbcacgheb","jffbejgghcehffegdc","jibedfbie","jah","ibiidfejdgdcj","iaeidag","ihihf","efcibiceag","gcieiigfdfdb","ajjjhfhf","cbfbabhgdb","gfgdb","hcdacdfabg","bigjbgifiaej","cigcd","ae","ge","aiihbafjecdea","beefbgiie","cgjgadiccedhc","cjdgcffbidfgeeafff","fhjgfffbba","bccach","eahfdaf","ahjdd","fihg","jbfjebg","cddahfafi","bbgbdaddhi","gdj","jeajeij","heghedag","jjchaicjjgfbg","abjgdiaejfbggi","acdchjidcjgbf","cejiijdjdhdfcee","jigaddhbgicdia","abc","agbjdbgjiehag","hfdigcigg","cgghefgejfhijdibdjg","hccieii","igcaddcchefdd","cgbbghdcihe","fecbhbibi","babjihei","i","d","jh","cifgachjchjbhaccc","bicbbbhhdbhiff","adedehahigage","ggchhigjicfieih","cdjjdcicfdgb","ideifebi","cfigg","cgeggchj","eefghjfgefhj","ddfdggagecjic","hjihgfaeii","ia","heidcecebahjbdfggdga","ecghbb","cejaeccaccdidia","gfehiajh","iffhjcgacb","jj","eaf","iajdhbaegee","aebhibdefdjg","iedhdj","hjjghaigbhabagag","gcgjabbhb","ceafidjdehiag","chadafai","hbedhgbhbjf","cjd","ffghjdedhcicibigi","egiegbjgfgafbfhjc","ihhdceihj","bejcfcchiifbe","fdgdibhfdjfbedhbe","faicaabjhdjhhhjijfc","hje","hiaijbcjidfcbfgcag","faeaifgei","dch","jgbffecigegeeadegj","aidgajdbdbaaa","gijf","ebedacfhedjedi","hbacgaahfdfjgi","fifgigbjgjgghhhd","j","ddjgbbiijjehchdbgbai","biga","bhfgcb","dhjadab","chdaiddifdffahcei","iafgaafifihabbgjj","cjegdheh","ehgdadgei","ehdfc","eacifidabdggjach","hhbhi","fcbbbbah","cegedidaigaci","cag","hegeiahfijhfciefd","dbab","gcgefhfjcgjhjecgddah","cdjgjjcjjicgbeih","ci","ijhjf","fbbgdeiageejdc","be","cjchgdgdgfagjjg","ibgeidbfa","fddggdhbddjaeddgdcfc","gcaggif","fjbgcgcgehbdbe","aicfjeichbeicfhecf","efie","hc","idfadbihjg","aaebdgc","fhjcgd","hhafdff","aabibgbfagajgjb","dghgcbggghgeaeg","fjgediahjigaa","fedgeeibjc","ejfejedc","bhaebiei","abgcbghfiedgehahcdci","bdhedihcbbffc","afhbdjjbd","fi","afdaicafe","jie","beagcaejegffega","aia","hi","jbighfjfcjahjgehe","bc","fadida","ighadgahjdghbb","bcifi","jiihgjheabbghfj","feejabbfgjgdcabdfbca","aedgdhcigb","ieaacbdebebh","dhhbbeeig","hieehbfibafgdhbg","fjfbegiaie","ccfaaigcaihejeijjaje","dadeacjcbfcfhhbij","eeecbheggdfjbecad","fjihfdgghjeae","hiffifdbj","ecidaedbfehehag","adegjjjc","cd","gf","ghfjagihccfcigige","bgf","chjgfeaieicigahh","cjiaddegfg","gdcgdij","dicehgcifif","fiidajechjiiijhbegbh","jefgfbhgdfciedagb","jjjgcbdjicabef","cdfid","edbfiicbefeajiic","ejbibi","cbhbihjeid","cabiiegaciib","gabbcdfijghgijicebj","jehfhhbfgegeg","jghffhffjf","dd","cjfaa","jifj","ibjiaihdcggcieaib","iifbiahhifgbacab","eebijggehcaijg","ejahjbhfchaa","ibibcfcbiec","dgdbgjcgcc","ageaibbdhjbfcbf","bhaedifejehbfibegeca","fejjhhcccccjeehgh","ahibaggjiacadbhefgec","ehigiijgd","ggbaabg","hh","heaajjgjggdigbb","aaejdigg","aiicbhfddcfjjbhhjjeh","ffaifijbhjbag","fahabbfdd","gbfhbhdfhhfjjcgaaj","abjfcge","adcfeecgbjhegi","chdddefcdf","bjhecbej","egib","da","jebagfj","behfe","higbgdiajeeehj","jib","idcghdbea","gdejgdcdihfbacaj","ajhiagcaahbfhadhib","ceejaidajdea","cde","bjfifjghfbc","eifiacecdci","jjafcaihfhej","afcaaibefidajhibag","dehd","hhiaifciaf","badjbageeeihbgcif","bcaeiidbijfhcid","abi","ah","ffefcc","fdieagiiajfafh","hcchdbihjdbec","ihidjiigibjf","edcdbcedacbjce","jbfdecgfbh","dacgadjgd","eejdhcfbdihbijcja","hbbj","gichdddfifgdaddajge","ffbcfbifeh","fjhaaidiifibhhejfidg","aeaehgfcbba","iihjefbjaifbda","adfiaaeajgic","jihdbcgbbiieigf","ecfiac","degf","idchfgeffdjiabgef","jb","eag","cgjadfejgjgc","iabghedbdheg","hiecdcegiecfjiedc","cigbaihic","jeechicij","edceggdjjeaa","ja","gdbdjeibhafgcfhgag","jeicf","jcgaadahjfbjihb","ghhiigfjaacii","ebiadgeh","ighd","jhaj","cfdiheagdihiicffbbh","jfdfc","jbedecaacicgd","fffcabach","e","ccebdc","jhgfghhjaijaabd","fdaidaeig","eeciegigac","hjjjaeiaaficijggdgh","c","babddddaeeffd","afdgbibgicccffgaee","hbhjbifbafhb","edcbhceeigd","hdgbheiadhcbfgj","dhidiiia","jjheg","ecjifcjdaacgdahcdid","ccjbdgbfhjiie","jajej","jjehhbedbfdi","ahffeh","gi","cjaghiejjhfdbgcijc","aibcfajefbihgde","ibjfiihieidfh","djceefcghhejjbd","djfdghagedbfhgid","dbh","hhfjcfghfcabidajaih","gj","eabaejcadggcgi","af","habi","idigfeaacffdhcfih","aaieehjfebihiaadfe","jjiadadfghgceicbbc","jej","fhecjeeibafgbac","icajjhihddfhehgcha","ihecchggh","jfichaagbicfhdcca","hgi","eeecaibagajdachadjcj","fda"]
    print (a.palindromePairs(a,l ))
