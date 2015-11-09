# A simple script that downloads, extracts and updates environment variables for TTCNv3
# Also downloads dependencies for TTCNv3
#
# Tested with Ubuntu 14.04, using bash

# To avoid locale issues
export LC_ALL="en_US.UTF-8"

# Folder to store TTCNv3 filse
TTCN3_DIR="/usr/local/ttcn3"

# Installs dependencies
sudo apt-get update
sudo apt-get -y upgrade
sudo apt-get install openssl libxml2-dev expect

# Creates TTCNv3 folder
sudo mkdir $TTCN3_DIR
cd $TTCN3_DIR

# Downloads and extracts TTCNv3
sudo wget http://saimei.acc.umu.se/mirror/eclipse.org/titan/ttcn3-5.3.pl0-linux64-gcc4.8-ubuntu14.04.tgz -O ttcn3.tgz
sudo tar xvfz ttcn3.tgz
sudo rm ttcn3.tgz

# Environment variables
ENV="
# ----------- TTCNv3 environment variables ----------- #
TTCN3_DIR=$TTCN3_DIR
PATH=\$PATH:\$TTCN3_DIR/bin
LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:\$TTCN3_DIR/lib
MANPATH=\$MANPATH:\$TTCN3_DIR/man
export TTCN3_DIR PATH LD_LIBRARY_PATH MANPATH
# ----------- End TTCNv3 environment variables ----------- #
"

# Writes environment variables to .bashrc
if ! grep -Fxq "source ~/.bashrc_ttcn3" ~/.bashrc
then
    echo "source ~/.bashrc_ttcn3" >>  ~/.bashrc
    fi

    echo "$ENV" >  ~/.bashrc_ttcn3
