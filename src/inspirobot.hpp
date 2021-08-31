#include "json.hpp"
#include <cpr/cpr.h>
#include <iomanip>
#include <iostream>

using json = nlohmann::json;
using namespace std;

const cpr::Url c_inspirobot = cpr::Url{"http://inspirobot.me/"};
const cpr::Url c_genr_url = cpr::Url{"api?generate=true"};
const cpr::Url c_sess_url = cpr::Url{"api?getSessionID=1"};
const cpr::Url c_flow_url = cpr::Url{"api?generateFlow=1&sessionID="};

std::string get_filename(std::string const &path)
{
    return path.substr(path.find_last_of("/\\") + 1);
}

std::tuple<cpr::Response, std::string> fetchSessionID(cpr::Session &session)
{
    std::string session_id = "";
    cpr::Response response;
    session.SetUrl(c_inspirobot + c_sess_url);
    response = session.Get();
    if (response.status_code == 200)
    {
        session_id = response.text;
    }
    return std::make_tuple(response, session_id);
}

void downloadFile(cpr::Session &session, cpr::Url &url_path)
{
    ofstream ofstream = std::ofstream(get_filename(url_path));
    session.SetUrl(url_path);
    session.Download(ofstream);
}

void fetchImage(cpr::Session &session)
{
    cpr::Response response;
    session.SetUrl(c_inspirobot + c_genr_url);
    response = session.Get();
    if (response.status_code == 200)
    {
        cpr::Url image = cpr::Url{response.text};
        downloadFile(session, image);
    }
}

void fetchAudio(cpr::Session &session)
{
    cpr::Response response;
    std::string session_id;
    std::string file_format = "mp3";

    std::tie(response, session_id) = fetchSessionID(session);
    if (response.status_code == 200 && session_id.size() != 0)
    {
        session.SetUrl(c_inspirobot + c_flow_url + session_id);
        json j_complete = json::parse(session.Get().text);
        std::string mp3_part = j_complete[file_format].get<std::string>();
        cpr::Url mp3 = cpr::Url{mp3_part};
        downloadFile(session, mp3);
    }
}
