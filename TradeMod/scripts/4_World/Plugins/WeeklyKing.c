// class BaseRequestData {
//     string USER_AGENT;
//     string CLIENT_ID;

//     void BaseRequestData () {
//         this.USER_AGENT = "603e6aa48728e10794f84968";
//         this.CLIENT_ID = "3H42ZUA0KDMFL9ERSOT7NVPY";
//     }
// };

// class CFAPIServiceVerifyResponse {
//     string access_token;
//     string refresh_token;
//     bool status;
// };


// class WeeklyKing
// {
// 	ref HeadHunterDMInfo HHDMInfo;
//     ref PlayerStatisticAllInfo kingData;

//     string USER_AGENT    = "";
//     string CLIENT_ID     = "";
//     string PLAIN_SECRET  = "";
//     string HASHED_SECRET = "";

//     private RestContext ctx;
//     private static string api_base = "https://cfapi.de/auth/login";
	
//     void SendKingRequest()
//     {
//         // KingRequestApi cbx1 = new KingRequestApi();
//         // RestContext ctx = GetRestApi().GetRestContext("https://cfapi.de/auth/login");
//         // ctx.GET(cbx1,"?key=900D3544BF634922D7A27DFBDCC6BDB6&filter=\\addr\\" + "212.22.93.181:27036" + "&limit=100");
//     }

//     string build_url(string secret) {
//         return "?secret=" + secret;
//     }

//     // void test() {
//     //     ref JsonSerializer json = new JsonSerializer;
//     //     string request_json, response_raw, error;

//     //     BaseRequestData request = new BaseRequestData();
//     //     json.WriteToString(request, false, request_json);
//     //     Print("====== DEBUG ======");
//     //     Print(request_json);
//     //     Print("====== DEBUG ======");

//     //     RestApi c_core = CreateRestApi();
//     //     c_core.EnableDebug(true);

//     //     ctx = c_core.GetRestContext(api_base);

//     //     response_raw = ctx.POST_now(build_url(HASHED_SECRET), request_json);

//     //     // CFAPIServiceVerifyResponse response = new CFAPIServiceVerifyResponse;
//     //     json.ReadFromString(response, response_raw, error);

//     //     Print("************* response_raw *************");
//     //     Print(response);
//     //     Print(response_raw);
//     //     Print(error);
//     // }


// 	void getKing () {
//         // this.check();

//         if (!FileExist(S_ROOTFOLDER + "HeadHunterDMInfo.json")) {
//             HHDMInfo = new HeadHunterDMInfo();
//             JsonFileLoader<ref HeadHunterDMInfo>.JsonSaveFile(S_ROOTFOLDER + "HeadHunterDMInfo.json",  HHDMInfo);       
//         } else {
//             JsonFileLoader<ref HeadHunterDMInfo>.JsonLoadFile(S_ROOTFOLDER + "HeadHunterDMInfo.json", HHDMInfo );   
//         }   
        
//         // if (!checkTime()) return;

// 		kingData = findKingInFileData();
// 		Print("################################ KING FOUND ################################");
// 		Print(kingData.steamID64);
// 		Print(kingData.playerName);

//         int f_year;
//         int f_month;
//         int f_day;    
//         GetYearMonthDay(f_year, f_month, f_day);

//         string checkDate = f_month.ToStringLen(2) + "-" + f_day.ToStringLen(2) + "-" + f_year;

//         HHDMInfo.kingUpdateDate = checkDate;
//         HHDMInfo.kingSteamID64 = kingData.steamID64;
//         JsonFileLoader<ref HeadHunterDMInfo>.JsonSaveFile(S_ROOTFOLDER + "HeadHunterDMInfo.json",  HHDMInfo);
// 	}

// 	bool checkTime () {
// 		int f_hour;
//         int f_minute;
//         int f_second;
//         int f_year;
//         int f_month;
//         int f_day;    
//         GetYearMonthDay(f_year, f_month, f_day);
//         GetHourMinuteSecond(f_hour, f_minute, f_second);

//         Print("Дата запуска: " + f_year.ToString() + ":" + f_month.ToString() + ":" + f_day.ToString());
//         Print("Время запуска: " + f_hour.ToString() + ":" + f_minute.ToString() + ":" + f_second.ToString());

//         string f_date = f_month.ToStringLen(2) + "-" + f_day.ToStringLen(2) + " " + f_hour.ToStringLen(2) + ":" + f_minute.ToStringLen(2) + ":" + f_second.ToStringLen(2);
//         Print("Date: " + f_date);

//         Print("номер дня недели равен: " + DateHH(f_day, f_month, f_year));

//         // если воскресение
//         if (DateHH(f_day, f_month, f_year) == 2) {
//         	string checkDate = f_month.ToStringLen(2) + "-" + f_day.ToStringLen(2) + "-" + f_year;

//         	Print("День недели сейчас вроде суббота");

//         	if (checkDate != HHDMInfo.kingUpdateDate) {
//         		Print("Вроде как не совпадает - обновим!");

//         		return true;
//         	} else {
// 	        	Print("А все уже все, дата совпадает, новый лидер уже выбран!");
//         	}
//         }

// 		return false;
// 	}

// 	int DateHH( int D, int M, int Y )
//     {

//         int a, y, m, R;
//         a = ( 14 - M ) / 12;
//         y = Y - a;
//         m = M + 12 * a - 2;
//         R = 7000 + ( D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12 );
//         int l  = R % 7;
//         int s = l;
//         return s;
//     }

//     	//  вот тут блэт могут быть косяки!
// 	ref PlayerStatisticAllInfo findKingInFileData () {
//     	// собираем всю информацию по игрокам
//         TStringArray fileNamesList = this.getAllPlayersList();
//         ref PlayerStatisticAllInfo _bestPlayerData = new PlayerStatisticAllInfo();
        
//         for ( int k = 0; k < fileNamesList.Count(); ++k ) {
//             string fileName = fileNamesList.Get(k);

//             if (!FileExist(S_COMMON + fileName + ".json"))
//                 continue; 

//             PlayerStatisticAllInfo _tmpBestPlayerData = new PlayerStatisticAllInfo();
//             JsonFileLoader<ref PlayerStatisticAllInfo>.JsonLoadFile(S_COMMON + fileName + ".json", _tmpBestPlayerData);

//         	if (_bestPlayerData.matchesWon == _tmpBestPlayerData.matchesWon) {
//         		// посмотреть по килам
//         		Print("тут совпали чуваки, покажу обоих");
//         		Print("Matches won: " + _bestPlayerData.matchesWon.ToString());
//         		Print(_bestPlayerData.playerName);
//         		Print(_bestPlayerData.steamID64);
//         		Print(_bestPlayerData.kills);
//         		Print(_bestPlayerData.deaths);

//         		Print(_tmpBestPlayerData.playerName);
//         		Print(_tmpBestPlayerData.steamID64);
//         		Print(_tmpBestPlayerData.kills);
//         		Print(_tmpBestPlayerData.deaths);

//         		if (_bestPlayerData.kills < _tmpBestPlayerData.kills) {
//         			_bestPlayerData = _tmpBestPlayerData;
//         			continue;
//         		}

//         		if ((_bestPlayerData.kills / _bestPlayerData.deaths) < (_tmpBestPlayerData.kills / _tmpBestPlayerData.deaths))
//         			_bestPlayerData = _tmpBestPlayerData;

//         	} else if (_bestPlayerData.matchesWon < _tmpBestPlayerData.matchesWon) {
//         		_bestPlayerData = _tmpBestPlayerData;
//         		Print("Matches won: " + _bestPlayerData.matchesWon.ToString());
//         		Print(_bestPlayerData.playerName);
//         		Print(_bestPlayerData.steamID64);
//         		Print(_bestPlayerData.kills);
//         	}
//         }

//         return _bestPlayerData;
//     }

// 	TStringArray getAllPlayersList()
//     {
//         if ( !FileExist( S_COMMON ) )
//             MakeDirectory( S_COMMON );

//         string  file_name;
//         int     file_attr;
//         int     flags;
//         TStringArray list = new TStringArray;
        
//         string path_find_pattern = S_COMMON + "/*.json";
//         FindFileHandle file_handler = FindFile(path_find_pattern, file_name, file_attr, flags);
        
//         bool found = true;
//         while ( found )
//         {
//             int pos = file_name.IndexOf(".");
            
//             if ( pos > -1 )
//                 list.Insert( file_name.Substring(0, pos) );
            
//             found = FindNextFile(file_handler, file_name, file_attr);
//         }

//         return list;
//     }
// }



// class KingRequestApi extends RestCallback
// {
//     override void OnError(int errorCode)
//     {
//         Print("[HHZ STEAM API] EROOR [" + errorCode + "]");
//     }

//     override void OnTimeout()
//     {
//         Print("[HHZ STEAM API] TIMEOUT");
//     }

//     override void OnSuccess(string data, int dataSize)
//     {
//         if (dataSize > 0)
//         {
//             if (!FileExist(S_ROOTFOLDER + "/KingRequestApi.json"))
//             {
//                 MakeDirectory(S_ROOTFOLDER);
//                 JsonFileLoader<KingRequestApi>.JsonSaveFile(S_ROOTFOLDER + "/KingRequestApi.json", NULL);
//             }
//             FileHandle file = OpenFile(S_ROOTFOLDER + "/KingRequestApi.json", FileMode.WRITE);

//             FPrintln(file, data);
//             CloseFile(file);

//             Print(data);
//         }
//     }
// };