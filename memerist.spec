Name:           memerist
Version:        2.0.0
Release:        1%{?dist}
Summary:        Meme generator with text overlays
License:        GPL-3.0-or-later
URL:            https://github.com/vani-tty1/memerist
Source0:        %{url}/archive/refs/tags/v%{version}/%{name}-%{version}.tar.gz
BuildRequires:  meson gcc pkgconfig(gtk4) pkgconfig(libadwaita-1) pkgconfig(cairo) appstream
BuildRequires:  desktop-file-utils blueprint-compiler libepoxy-devel ImageMagick ImageMagick-devel
Requires:       gtk4 libadwaita ImageMagick
%description
Create memes with custom text overlays using a native GNOME interface.

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
* Mon Aug 17 2026 Giovanni Rafanan <giovannirafanan609@gmail.com> - 2.0.0-1
- Minimum version required for libadwaita increased from 1.4 to 1.9.
- New welcome screen.
- Update to latest ImageMagick.
- Templates are now in its separate window.
- Improve template management.
- Built-in templates are now deletable but can also be restored.
- GIF's are now displayed and animated correctly in the preview.
- Fixed double shadow appearing in the app icon in about_dialog.
