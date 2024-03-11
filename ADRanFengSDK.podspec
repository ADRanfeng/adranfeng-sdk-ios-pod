#
# Be sure to run `pod lib lint ADRanFengSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ADRanFengSDK'
  s.version          = '2.1.0.1-noidfa'
  s.summary          = 'A short description of ADRanFengSDK.'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/ADRanfeng/adranfeng-sdk-ios-pod.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = {"business@ssdmobile.cn"=>"business@ssdmobile.cn"}
  s.source           = { :git => 'https://github.com/ADRanfeng/adranfeng-sdk-ios-pod.git', :tag => s.version.to_s }
  
  s.vendored_frameworks = 'ADRanFengSDK/Classes/*.xcframework'

  s.dependency 'ADRFMediationKit', '0.7.0.06291-noidfa'
  s.dependency 'ADRFMediationNetwork', '~> 0.2.1.0'
  s.dependency 'ADRFMediationLocationManager', '~> 0.2.0.0'

  s.ios.deployment_target = '9.0'
  s.static_framework = true
  s.requires_arc = true
  s.frameworks = "StoreKit","WebKit"
  s.libraries = ["resolv.9"]
  
  s.xcconfig = {
      'OTHER_LDFLAGS' => '-ObjC',
  }


end


