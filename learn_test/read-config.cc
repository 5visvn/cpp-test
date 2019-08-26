#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

std::string m_Url,
   HistoryUrl,
   m_Interval,
   m_hisInterval,
   m_DisSendMode,
   m_DelayTime,
   m_DataProcTime,
   m_CacheHour,
   m_HisPath,
   edge_dpf_path,
   path_unzip;

int Readfigconf(const char* path_conf_file)
{
	// if (path_conf_file == NULL)
	// {
	// 	PrintLogm(&logger, FEDGE_C_LOG_ERROR, "path_fig_conf is NULL\n");
	// 	return -1;
	// }
  std::ifstream stufile(path_conf_file);

	if (!stufile.is_open())
	{
		// PrintLogm(&logger, FEDGE_C_LOG_ERROR, "Readfigconf:open cfig.conf fail\n");
     std::cout << "no file";
		return -1;
		//exit(EXIT_FAILURE);
	}

  std::string buff;
  std::string prefix("config-client.");
  std::string server("server.");
  std::string post("post.");



  while (std::getline(stufile, buff))
  {
     std::size_t index = buff.find_first_of('#');
     if (index != std::string::npos)
        buff = buff.substr(0, index);

     // remove space and tab
     buff.erase(std::remove(buff.begin(), buff.end(), ' '), buff.end());
     buff.erase(std::remove(buff.begin(), buff.end(), '\t'), buff.end());

     // empty or comment line
     if (buff.empty())
        continue;

     // get key and value
     index = buff.find_first_of('=');
     if (index != std::string::npos)
     {
        std::string key = buff.substr(0, index);
        std::string value = buff.substr(index + 1 , buff.length() - 1);

        if (key == (prefix + server + "url"))
           m_Url = value;
        else if (key == (prefix + server + "historyurl"))
           HistoryUrl = value;
        else if (key == (prefix + post + "m_Interval"))
           m_Interval = value;
        else if (key == (prefix + post + "m_hisInterval"))
           m_hisInterval = value;
        else if (key == (prefix + post + "m_DisSendMode"))
           m_DisSendMode = value;
        else if (key == (prefix + post + "m_DelayTime"))
           m_DelayTime = value;
        else if (key == (prefix + post + "m_DataProcTime"))
           m_DataProcTime = value;
        else if (key == (prefix + post + "m_CacheHour"))
           m_CacheHour = value;
        else if (key == (prefix + post + "m_HisPath"))
           m_HisPath = value;
        else if (key == (prefix + post + "edge_dpf_path"))
           edge_dpf_path = value;
        else if (key == (prefix + post + "path_unzip"))
           path_unzip = value;
        else
           std::cout << "unknow parameter!\n";
     }
     else
     {
        std::cout << "error format\n";
     }

  }


  std::cout << "output: " << std::endl << m_Url << std::endl
            << HistoryUrl << std::endl
            << m_Interval << std::endl
            << m_hisInterval << std::endl
            << m_DisSendMode << std::endl
            << m_DelayTime << std::endl
            << m_DataProcTime << std::endl
            << m_CacheHour << std::endl
            << m_HisPath << std::endl
            << edge_dpf_path << std::endl
            << path_unzip << std::endl;

  return 0;



}

int main()
{
   Readfigconf("./test_conf.cfg");
}
