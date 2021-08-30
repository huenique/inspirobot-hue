#include <cpr/cpr.h>

using namespace std;

cpr::Url url_string = cpr::Url{"http://inspirobot.me/api?generate=true"};
cpr::Session session;

std::string filename(std::string const &path)
{
    return path.substr(path.find_last_of("/\\") + 1);
}

int fetchImage()
{
    session.SetUrl(url_string);
    cpr::Response response = session.Get();
    if (response.status_code == 200)
    {
        ofstream ofstream = std::ofstream(filename(response.text));
        session.SetUrl(cpr::Url{response.text});
        session.Download(ofstream);
    }
    return 0;
}

int main(int argc, char **argv)
{
    fetchImage();
    return 0;
}
