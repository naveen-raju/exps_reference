Name:pml-scaleout-configuration
Version:%{version}
Release:0
Summary: PML scaleout NAS / Hyperconverged product configuration
Group: Managebility/control path
License:Commercial
Vendor: Hewlett-Packar Enterprise

%define tmp_prefix /tmp
%define _topdir %{myrpmbuilddir}
%define _tgt_dir /usr/local/pml/conf/productconfiguration/
%define _hpsp_config hpsp-monitor-eventsuppression.properties
%define _network_config network-services.properties
%define _core_config core-config.properties
%define _file_config fileservices-config.properties

buildroot: %{_tmppath}/%{name}-%{version}/

%description
This package contains the PML product congfiguration files for scaleout NAS/Hyperconverged appliance

%prep

%build

%install
rm -rf $RPM_BUILD_ROOT
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/pml/
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/pml/conf/
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/pml/conf/productconfiguration
install -m 0755 %{_topdir}/%{_hpsp_config} $RPM_BUILD_ROOT/%{_tgt_dir}/
install -m 0755 %{_topdir}/%{_network_config} $RPM_BUILD_ROOT/%{_tgt_dir}/
install -m 0755 %{_topdir}/%{_core_config} $RPM_BUILD_ROOT/%{_tgt_dir}/
install -m 0755 %{_topdir}/%{_file_config} $RPM_BUILD_ROOT/%{_tgt_dir}/

%post 

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%{_tgt_dir}/%{_hpsp_config}
%{_tgt_dir}/%{_network_config}
%{_tgt_dir}/%{_core_config}
%{_tgt_dir}/%{_file_config}

%doc

%changelog
* Mon Sep 12 2016 Naveen Raju <naveen-raju.b@hpe.com>
Creation of new product configuration rpm for scaleout NAS and Hyperconverged storage appliance 
