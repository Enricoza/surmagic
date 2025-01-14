# Contributing to _surmagic_

## If you see a way to improve the project or want to report a problem or ask a question

Before submitting a new GitHub issue, please make sure to:

- Check out the [README](https://github.com/gurhub/surmagic) page on this repo
- Check out [surmagic wiki](https://github.com/gurhub/surmagic/wiki)
- Search for existing GitHub issues
- If you'd like to **ask a general question**, use [Stack Overflow](https://stackoverflow.com/questions/tagged/surmagic).
- If you **have a feature request**, open an [issue](https://github.com/gurhub/surmagic/issues).
- If you **want to contribute**, submit a [pull request](https://github.com/gurhub/surmagic/pulls). It's better to begin with an [issue](https://github.com/gurhub/surmagic/issues) rather than a [pull request](https://github.com/gurhub/surmagic/pulls), though, because we might disagree whether the proposed change is an actual improvement. :wink:
- If you **found a bug**, _and can provide steps to reliably reproduce it_, or the above doesn't help, please submit [an issue](https://github.com/gurhub/surmagic/issues) on GitHub and provide information about your setup via the Bug Report Issue Template.

Thanks! :v:

## Here are some ToDo candidates For You

- [ ] Add surmagic/report.xml for -Xcode build archive- process
- [ ] Add Github title image **👉Need Contribution here!** Not just an image actually an banner for the repository/tool.


## How to build and test the binary locally

- Open the `Package.swift` file
- Archive the `surmagic` target for `Any Mac`
- After it completes, right click on the new archive and `Show in Finder`
- Right click on the archive and `Show Package Contents`
- Navigate to `Products/usr/local/bin`
- Copy the `surmagic` binary in that folder and paste it on the root of the project, under the `bin` folder
- Navigate to a Demo project folder like `/Demo/project-demo/xcf`
- Run the command `../../../bin/surmagic xcf --verbose` which uses the newly created binary

## How to distribute the binary

- Make sure you have updated the version in the `main.swift` file
- Make sure to build the binary as expressed in the above process
- Go to the `bin` folder and codesign the binary `codesign --timestamp -s XXXXXXX surmagic -o runtime` 
  - Make sure to replace XXXXXXX with your Developer ID Application certificate name
- Compress the binary and codesign the zip as well `codesign --timestamp -s XXXXXXX surmagic.zip -o runtime`
- Notarize the file for distribution `xcrun notarytool submit surmagic.zip --keychain-profile "notarytool"`
  - "notarytool" is the name you give to a custom keychain profile containing the [app specific password](https://support.apple.com/en-us/102654) that you created for this.
  - More on Notarization [here](https://developer.apple.com/documentation/security/customizing-the-notarization-workflow#Upload-your-app-to-the-notarization-service)
- Commit and push to master
- Create a new release on github and upload the zip there