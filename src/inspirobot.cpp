#include "inspirobot.hpp"
#include "cli.hpp"

int main(int argc, char *argv[])
{
    if (cmdOptionExists(argv, argv + argc, "-h"))
    {
        showHelp(argv);
    }

    char *filename = getCmdOption(argv, argv + argc, "--file");

    if (filename)
    {
        cpr::Session session;
        if (filename[0] == 'i')
        {
            fetchImage(session);
        }
        else
        {
            fetchAudio(session);
        }
    }
    return 0;
}
