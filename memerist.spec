Name:           memerist
Version:        2.1.0
Release:        1%{?dist}
Summary:        A simple meme editor for Linux
License:        GPL-3.0-or-later
URL:            https://github.com/vani-tty1/memerist
Source0:        %{url}/archive/refs/tags/v%{version}/%{name}-%{version}.tar.gz
BuildRequires:  meson ninja-build gcc gtk4-devel libadwaita-devel appstream
BuildRequires:  desktop-file-utils blueprint-compiler libepoxy-devel ImageMagick ImageMagick-devel
Requires:       gtk4 libadwaita ImageMagick libepoxy 

%description
Simple meme editor for Linux 

%prep
%autosetup -n memerist-%{version}

%build
%meson
%meson_build

%install
%meson_install

%check
%meson_test


%files
%{_bindir}/memerist
%{_datadir}/applications/io.github.vani_tty1.memerist.desktop
%{_datadir}/glib-2.0/schemas/io.github.vani_tty1.memerist.gschema.xml
%{_datadir}/icons/hicolor/scalable/apps/io.github.vani_tty1.memerist.svg
%{_datadir}/icons/hicolor/symbolic/apps/io.github.vani_tty1.memerist-symbolic.svg
%{_datadir}/metainfo/io.github.vani_tty1.memerist.metainfo.xml


%changelog
* Tue Sep 01 2026 Giovanni Rafanan <giovannirafanan609@gmail.com> - 2.1.0-1
- New freehand drawing tool
- GIF's can now be imported to templates
- Minor UI adjustments
