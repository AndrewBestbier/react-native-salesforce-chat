require 'json'

package = JSON.parse(File.read(File.join(__dir__, 'package.json')))

Pod::Spec.new do |s|
  s.name         = package['name']
  s.version      = package['version']
  s.summary      = package['description']
  s.license      = package['license']

  s.authors      = package['author']
  s.homepage     = package['homepage']
  s.platform     = :ios, "9.0"

  s.source       = { :git => "https://github.com/AndrewBestbier/react-native-salesforce-chat", :tag => "v#{s.version}" }
  s.source       = { :git => "https://github.com/CocoaPods/Specs.git" }
  s.source       = { :git => "https://github.com/goinstant/pods-specs-public" }
  s.source_files  = "ios/**/*.{h,m}"
  s.dependency 'React'
  s.dependency 'ServiceSDK', '222.0.2'
end