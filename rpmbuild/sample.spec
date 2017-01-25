Name:Sample
Version:%{version}
Release:0
Summary: Sample
Group: Sample 
License:BSA
Vendor: Naveen

%define tmp_prefix /tmp
%define _topdir %{myrpmbuilddir}
%define _file_config sample.sh 
This package contains the sample.sh script containing nothing

%prep

%build

%install
rm -rf $RPM_BUILD_ROOT
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/bin
install -m 0755 %{_topdir}/%{_file_config} $RPM_BUILD_ROOT/%{_tgt_dir}/

%post 

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%{_tgt_dir}/%{_file_config}

%doc

%changelog
* Mon Jan 12 2017 Naveen Raju <naveenjce@gmail.com>
Creation of new sample rpm  
