
package org.andrewbestbier.salesforcechat;

import java.util.LinkedList;

import android.support.annotation.NonNull;
import android.support.v4.app.FragmentActivity;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;

import com.salesforce.android.chat.core.ChatConfiguration;
import com.salesforce.android.chat.core.model.AvailabilityState;
import com.salesforce.android.chat.core.model.PreChatField;
import com.salesforce.android.chat.core.model.PreChatEntityField;
import com.salesforce.android.chat.core.model.PreChatEntity;
import com.salesforce.android.chat.ui.ChatUI;
import com.salesforce.android.chat.ui.ChatUIClient;
import com.salesforce.android.chat.ui.ChatUIConfiguration;
import com.salesforce.android.service.common.utilities.control.Async;
import com.salesforce.android.chat.core.AgentAvailabilityClient;
import com.salesforce.android.chat.core.ChatCore;


public class RNSalesforceChatModule extends ReactContextBaseJavaModule {

    private static final String TAG = "RNSalesforceChat";

    private final ReactApplicationContext reactContext;

    public RNSalesforceChatModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return TAG;
    }


    private LinkedList<PreChatField> preChatFields = new LinkedList<>();

    private LinkedList<PreChatEntity> preChatEntities = new LinkedList<>();

    private ChatConfiguration chatConfiguration;


    @ReactMethod
    public void configLaunch(ReadableMap chatSettings, ReadableMap userSettings) {

        preChatFields.clear();
        preChatEntities.clear();

        // Some required fields (Hidden)
        PreChatField subject = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("subject")).build("Subject", "Subject", PreChatField.STRING);
        PreChatField origin = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("origin")).build("Origin", "Origin", PreChatField.STRING);
        PreChatField currency = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("currencyISOCode")).build("CurrencyIsoCode", "CurrencyIsoCode", PreChatField.STRING);
        PreChatField status = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("status")).build("Status", "Status", PreChatField.STRING); //Hardcoded
        PreChatField contactType = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("contactType")).build("ContactType__c", "ContactType__c", PreChatField.STRING); //Hardcoded
        PreChatField locale = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("locale")).build("Locale__c", "Locale__c", PreChatField.STRING);
        PreChatField canTSBeDone = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("canTSBeDone")).build("CanTroubleshootingbedone__c", "CanTroubleshootingbedone__c", PreChatField.STRING);
        PreChatField type = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("type")).build("ProductV2__c", "ProductV2__c", PreChatField.STRING);
        PreChatField product = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("subject")).build("EquipmentV2__c", "EquipmentV2__c", PreChatField.STRING);
        PreChatField model = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("model")).build("Version__c", "Version__c", PreChatField.STRING);
        PreChatField pointOfUserJourney = new PreChatField.Builder().hidden(true)
                .value(chatSettings.getString("pointOfUserJourney")).build("PointOfCustomerJourney__c", "PointOfCustomerJourney__c", PreChatField.STRING);
        PreChatField suppliedEmail = new PreChatField.Builder().hidden(true)
                .value(userSettings.getString("email")).build("SuppliedEmail", "SuppliedEmail", PreChatField.EMAIL);
        PreChatField suppliedName = new PreChatField.Builder().hidden(true)
                .value(userSettings.getString("suppliedName")).build("SuppliedName", "SuppliedName", PreChatField.STRING);
        //An unique identification of an engineer

        // Some optional fields (Hidden)
        PreChatField email = new PreChatField.Builder().hidden(true)
                .value(userSettings.getString("email")).build("Email", "Email", PreChatField.EMAIL);
        //An unique identification of an engineer

        // Add the fields to the list
        preChatFields.add(subject);
        preChatFields.add(origin);
        preChatFields.add(currency);
        preChatFields.add(status);
        preChatFields.add(contactType);
        preChatFields.add(locale);
        preChatFields.add(suppliedEmail);
        preChatFields.add(suppliedName);
        preChatFields.add(email);
        preChatFields.add(canTSBeDone);
        preChatFields.add(type);
        preChatFields.add(product);
        preChatFields.add(model);
        preChatFields.add(pointOfUserJourney);


        // Create an entity field builder for Case fields
        PreChatEntityField.Builder caseEntityBuilder = new PreChatEntityField.Builder()
                .doCreate(true);

        // Create the case entity
        PreChatEntity caseEntity = new PreChatEntity.Builder()
                .saveToTranscript("Case")
                .addPreChatEntityField(caseEntityBuilder.build("Subject", "Subject"))
                .addPreChatEntityField(caseEntityBuilder.build("Origin", "Origin"))
                .addPreChatEntityField(caseEntityBuilder.build("CurrencyIsoCode", "CurrencyIsoCode"))
                .addPreChatEntityField(caseEntityBuilder.build("Status", "Status"))
                .addPreChatEntityField(caseEntityBuilder.build("ContactType__c", "ContactType__c"))
                .addPreChatEntityField(caseEntityBuilder.build("Locale__c", "Locale__c"))
                .addPreChatEntityField(caseEntityBuilder.build("SuppliedEmail", "SuppliedEmail"))
                .addPreChatEntityField(caseEntityBuilder.build("SuppliedName", "SuppliedName"))
                .addPreChatEntityField(caseEntityBuilder.build("CanTroubleshootingbedone__c", "CanTroubleshootingbedone__c"))
                .addPreChatEntityField(caseEntityBuilder.build("ProductV2__c", "ProductV2__c"))
                .addPreChatEntityField(caseEntityBuilder.build("EquipmentV2__c", "EquipmentV2__c"))
                .addPreChatEntityField(caseEntityBuilder.build("Version__c", "Version__c"))
                .addPreChatEntityField(caseEntityBuilder.build("PointOfCustomerJourney__c", "PointOfCustomerJourney__c"))
                .build("Case");
        // Add the entities to the list
        preChatEntities.add(caseEntity);
    }

    @ReactMethod
    public void configChat(String ORG_ID, String DEPLOYMENT_ID, String BUTTON_ID, String LIVE_AGENT_POD, String VISITOR_NAME) {
        chatConfiguration = new ChatConfiguration.Builder(ORG_ID, BUTTON_ID, DEPLOYMENT_ID, LIVE_AGENT_POD)
                .preChatFields(preChatFields)
                .preChatEntities(preChatEntities)
                .visitorName(VISITOR_NAME)
                .build();
    }


    @ReactMethod
    public void launch(final Callback successCallback) {

        // Create an agent availability client
        AgentAvailabilityClient client = ChatCore.configureAgentAvailability(chatConfiguration);

        client.check().onResult(new Async.ResultHandler<AvailabilityState>() {
            @Override
            public void handleResult(Async<?> async, @NonNull AvailabilityState state) {

                switch (state.getStatus()) {
                    case AgentsAvailable: {
                        startChat();
                        break;
                    }
                    case NoAgentsAvailable: {
                        successCallback.invoke();
                        break;
                    }
                    case Unknown: {
                        break;
                    }
                }
                ;
            }
        });
    };



    private void startChat() {
      ChatUIConfiguration chatUiConfiguration =
        new ChatUIConfiguration.Builder()
          .chatConfiguration(chatConfiguration)
          .disablePreChatView(true)
          .build();
        ChatUI.configure(chatUiConfiguration)
                .createClient(reactContext)
                .onResult(new Async.ResultHandler<ChatUIClient>() {

                        @Override public void handleResult (Async<?> operation,
                                                        @NonNull ChatUIClient chatUIClient) {
                        chatUIClient.startChatSession((FragmentActivity) getCurrentActivity());
                        }
                });
    };

}
