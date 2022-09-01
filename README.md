# react-native-salesforce-chat

## Getting started

`$ npm install react-native-salesforce-chat --save`

### Mostly automatic installation

`$ react-native link react-native-salesforce-chat`

### Manual installation

#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-salesforce-chat` and add `RNSalesforceChat.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNSalesforceChat.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.reactlibrary.RNSalesforceChatPackage;` to the imports at the top of the file
  - Add `new RNSalesforceChatPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-salesforce-chat'
  	project(':react-native-salesforce-chat').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-salesforce-chat/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      implementation project(':react-native-salesforce-chat')
  	```

## Usage
```javascript
import RNSalesforceChat from 'react-native-salesforce-chat';
```
