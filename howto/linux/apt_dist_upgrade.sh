sudo cp /etc/apt/sources.list /etc/apt/sources.list.backup
sudo sed "s/bullseye/bookworm/g" /etc/apt/sources.list.backup > /etc/apt/sources.list
sudo apt update
sudo apt dist-upgrade
