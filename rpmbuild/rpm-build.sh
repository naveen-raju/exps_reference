BUILDTIME=`date +%Y%m%d%H%M%S`
BUILDDIR="."
echo $PWD
RPMBUILDDIR=$PWD
RPMHOME=$RPMBUILDDIR/target

if [ $# -gt 0 ];then
    version_str=$1
else 
    version_str="1"
fi

echo "Starting RPM build..."
echo "creating Build directories"

if [ ! -d $BUILDDIR/BUILD ]; then
    mkdir -p $BUILDDIR/BUILD
fi

if [ ! -d $BUILDDIR/BUILDROOT ]; then
    mkdir -p $BUILDDIR/BUILDROOT
fi

if [ ! -d $BUILDDIR/SPECS ]; then
    mkdir -p $BUILDDIR/SPECS
fi

if [ ! -d $BUILDDIR/SOURCES ]; then
    mkdir -p $BUILDDIR/SOURCES
fi

if [ ! -d $BUILDDIR/SRPMS ]; then
    mkdir -p $BUILDDIR/SRPMS
fi

if [ ! -d $BUILDDIR/RPMS ]; then
    mkdir -p $BUILDDIR/RPMS
fi

if [ ! -d $BUILDDIR/LOGS ]; then
    mkdir -p $BUILDDIR/LOGS
fi

mkdir $BUILDDIR/tmp > /dev/null 2>&1

rpmbuild -vv --ba sample.spec -D "buildtime $BUILDTIME" -D "myrpmbuilddir $RPMBUILDDIR" -D "version $version_str" >> $BUILDDIR/LOGS/build.log 2>&1
if [ $? -eq 0 ]; then
    echo "* RPM build successfully - scaleout product configuration. Check LOGS folder for more details."
else
    echo "* Failed building commands. scaleout product configuration. (LOGS/build.log)"
    exit 1
fi

mkdir -p $RPMHOME/ > /dev/null 2>&1
mv $RPMBUILDDIR/RPMS/x86_64/*.rpm $RPMHOME/
ls -ltr $RPMHOME/*

rm -rf $BUILDDIR/BUILD > /dev/null 2>&1
rm -rf $BUILDDIR/BUILDROOT > /dev/null 2>&1
rm -rf $BUILDDIR/SPECS > /dev/null 2>&1
rm -rf $BUILDDIR/SOURCES /dev/null 2>&1
rm -rf $BUILDDIR/SRPMS > /dev/null 2>&1
rm -rf $BUILDDIR/RPMS > /dev/null 2>&1
rm -rf $BUILDDIR/LOGS > /dev/null 2>&1
rm -rf $BUILDDIR/tmp > /dev/null 2>&1
